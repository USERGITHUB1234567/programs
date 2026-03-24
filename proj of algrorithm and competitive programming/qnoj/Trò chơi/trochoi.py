def ngay_khong_choi(N: int, K: int) -> int:
    # day là chỉ số ngày hiện tại (bắt đầu từ 1)
    day = 1

    # Nếu có thể hoàn thành ít nhất một chu kỳ 5 ngày và K >= 10 => vô hạn
    if N >= 10 and K >= 10:
        return 0

    # Nếu có thể thực hiện nhiều chu kỳ 5 ngày và K < 10, nhảy theo chu kỳ
    if K < 10 and N >= 10:
        D = 10 - K  # mất ròng mỗi chu kỳ 5 ngày
        # số chu kỳ liên tiếp có thể thực hiện sao cho trước mỗi chu kỳ N >= 10
        m = (N - 10) // D + 1
        N -= m * D
        day += m * 5

    # Mô phỏng từng ngày còn lại
    while True:
        if N < 2:
            return day
        # trừ 2 xu vào đầu ngày
        N -= 2
        # nếu là ngày thứ 5 của một chu kỳ, cộng K sau khi trừ
        if day % 5 == 0:
            N += K
        day += 1

# Đọc input và in kết quả
if __name__ == "__main__":
    import sys
    data = sys.stdin.read().strip().split()
    N = int(data[0])
    K = int(data[1])
    print(ngay_khong_choi(N, K))
