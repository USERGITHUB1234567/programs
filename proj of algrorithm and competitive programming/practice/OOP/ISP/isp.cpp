#include <iostream>
#include <stdexcept>
#include <string>

// -------------------------------------------------------------
// GIAO DIỆN DỊCH VỤ ĐẶT MÓN
// [Thảo luận]: Interface này đang quy định "luật chơi" cho TẤT CẢ các hình thức bán hàng.
// Liệu mọi hình thức bán hàng đều có thực đơn giống hệt nhau không?
// -------------------------------------------------------------
/* class IOrderService {
public:
    virtual void OrderBurger(int quantity) = 0;
    virtual void OrderFries(int quantity) = 0;
    
    // [Vấn đề]: Hàm này được đặt ở đây với giả định "Ai bán Burger thì cũng bán Combo".
    // Điều này có luôn đúng không?
    virtual void OrderComboSet(int quantity) = 0; 

    virtual ~IOrderService() {}
}; */
class IOrderServiceSingle {
public:
    virtual void OrderBurger(int quantity)=0;
    virtual void OrderFries(int quantity)=0;
    virtual ~IOrderServiceSingle() {}
};
class IOrderServiceCombo {
public:
    virtual void OrderComboSet(int quantity)=0;
};
// -------------------------------------------------------------
// KÊNH 1: ĂN TẠI CHỖ (Dine In)
// Kênh này hỗ trợ đầy đủ menu -> Không có vấn đề gì.
// -------------------------------------------------------------
class DineInService : public IOrderServiceCombo,public IOrderServiceSingle {
public:
    void OrderBurger(int quantity) override {
        std::cout << "Dine-In: Đã order " << quantity << " Burger.\n";
    }

    void OrderFries(int quantity) override {
        std::cout << "Dine-In: Đã order " << quantity << " Khoai tây chiên.\n";
    }

    void OrderComboSet(int quantity) override {
        std::cout << "Dine-In: Đã order " << quantity << " Combo Tiết kiệm.\n";
    }
};

// -------------------------------------------------------------
// KÊNH 2: GIAO HÀNG APP (Online Delivery)
// [Bối cảnh]: Chính sách công ty không cho bán Combo qua App (do khó vận chuyển).
// -------------------------------------------------------------
class OnlineDeliveryService : public IOrderServiceSingle {
public:
    void OrderBurger(int quantity) override {
        std::cout << "Online: Đã thêm " << quantity << " Burger vào giỏ.\n";
    }

    void OrderFries(int quantity) override {
        std::cout << "Online: Đã thêm " << quantity << " Khoai tây chiên vào giỏ.\n";
    }

    // [Vấn đề]: Vì kế thừa IOrderService, class này BỊ ÉP phải có hàm OrderComboSet.
    // Lập trình viên buộc phải xử lý bằng cách ném lỗi hoặc để trống.
    // Đây có phải là một thiết kế an toàn không?
    /* void OrderComboSet(int quantity) override {
        // Code chống chế
        throw std::logic_error("Lỗi: Khách Online không được mua Combo!");
    } */
};

// -------------------------------------------------------------
// MODULE XỬ LÝ ĐƠN HÀNG TỰ ĐỘNG
// -------------------------------------------------------------
void AutoOrderLunch(IOrderServiceSingle* service) {
    std::cout << "--- Bắt đầu đặt bữa trưa tự động ---\n";
    service->OrderBurger(1);
    
    // [Nguy hiểm]: Hàm này không hề biết 'service' là Online hay DineIn.
    // Nó cứ gọi OrderComboSet vì Interface bảo "có hàm này".
    // Chuyện gì xảy ra nếu service truyền vào là OnlineDeliveryService?
    /* try {
        service->OrderComboSet(1); 
    } catch (const std::exception& e) {
        std::cerr << "!!! CRITICAL ERROR: " << e.what() << "\n";
    } */
}

int main() {
    DineInService table1;
    OnlineDeliveryService appUser;

    // Test khách ăn tại bàn
    AutoOrderLunch(&table1); 

    std::cout << "\n";

    // Test khách đặt qua App
    // [Thảo luận]: Tại sao chương trình lại crash (hoặc báo lỗi) 
    // dù trình biên dịch (Compiler) không báo sai cú pháp?
    AutoOrderLunch(&appUser);

    return 0;
}
