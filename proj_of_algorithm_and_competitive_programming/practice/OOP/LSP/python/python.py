from abc import ABC, abstractmethod

class PaymentMethod(ABC):
    @abstractmethod
    def process_payment(self, amount):
        pass

    '''@abstractmethod
    def validate_security_code(self, security_code):
        pass'''
    def validate_payment_details(self,info):
        print(f"phuong thuc nay khong yeu cau xac thuc them{info}")
        return True
class secure_payment(ABC):
    def validate_security_code(self,code):
        print(f"")
class CreditCard(PaymentMethod):
    def process_payment(self, amount):
        print(f"Đã thanh toán ${amount} qua thẻ tín dụng.")

    def validate_payment_details(self, info):
        print(f"Đang kiểm tra mã CVV: {info}")
        if(len(info)!=3):raise ValueError("ma khong hop le")
        else: print("ma hop le")

class PayPal(PaymentMethod):
    def process_payment(self, amount):
        print(f"Đã thanh toán ${amount} qua PayPal.")

    def validate_payment_details(self, info):
        # PayPal đăng nhập bằng email/pass, không có mã bảo mật 3 số như thẻ!
        #raise NotImplementedError("PayPal không dùng mã bảo mật CVV!")
        print(f"")

# --- Client Code (Hệ thống của cửa hàng) ---
def checkout(payment_method: PaymentMethod, amount, info):
    try:
        # Cửa hàng mặc định mọi phương thức đều cần check security code
        payment_method.validate_payment_details(info)
        payment_method.process_payment(amount)
    except Exception as e:
        print(f"Lỗi thanh toán: {e}")

# Chạy thử
the_visa = CreditCard()
vi_paypal = PayPal()

print("--- KH 1: Dùng Thẻ ---")
checkout(the_visa, 100, "123")

print("\n--- KH 2: Dùng PayPal ---")
checkout(vi_paypal, 50, "999") # <--- Vấn đề nằm ở đây
