import matplotlib.pyplot as plt
from main import *

data = "HELLO4"

# Bước 1: Mã hóa UTF-8
utf8_data = utf8_encode(data)
print("Dữ liệu mã hóa UTF-8:", utf8_data)

# Bước 2: Kiểm tra lỗi CRC-8
crc = crc8(utf8_data)
print("CRC-8:", crc)

# Bước 3: Kết hợp dữ liệu và CRC
encoded_data = utf8_data + crc
print("Dữ liệu với CRC-8:", encoded_data)

# Bước 4: Mã hóa NRZ-I (bắt đầu từ trạng thái thấp)
data_pulse = read_from_pulse(encoded_data)
print("Dữ liệu xung (nhận):", data_pulse)

data_received = nrzi_decode(data_pulse)
print("Dữ liệu bên nhận giải mã:", data_received)

if crc8_check(data_received):
    print("CRC nhận là đúng!")
    binary_data = data_received[:-8]  # Bỏ phần CRC đi
    text = ""
    for i in range(0, len(binary_data), 8):
        byte_string = binary_data[i:i + 8] # Cắt 8 bit 1 lần lặp
        character = chr(int(byte_string, 2))  # Chuyển đổi chuỗi nhị phân thành ký tự
        text += character
    print("Decoded text:", text)
else:
    print("CRC check failed, data might be corrupted.")

# ============================ Vẽ tín hiệu ============================

# Tạo tín hiệu NRZ-I
time, voltage_nrzi = plot_signal_combined(data_pulse,"Tín hiệu NRZ-I")

# Chỉ tạo nhiễu với đúng 56 bit (mỗi bit có 2 mẫu)
noise_length = len(voltage_nrzi)  # Tương ứng với độ dài tín hiệu NRZ-I
noise = create_noise(noise_length)
voltage_with_noise = voltage_nrzi + noise

# ===================== Vẽ 3 Hình theo hàng dọc ==========================
fig, axs = plt.subplots(3, 1, figsize=(12, 18))  # Tăng kích thước cho hình ảnh

# Hình 1: Tín hiệu NRZ-I
axs[0].step(time, voltage_nrzi, where='post', color='green')
axs[0].set_title("NRZ-I Signal")
axs[0].set_ylabel('Voltage Level (V)')
axs[0].set_ylim(0, 7)
axs[0].grid()

bit_duration = 1  # Thời gian của mỗi bit tương ứng với 1 đơn vị thời gian
for i, bit in enumerate(encoded_data):
    # Tính toán vị trí x cho mỗi bit, mỗi bit có 2 mẫu
    x_pos_start = i * bit_duration  # Bắt đầu vị trí của bit
    x_pos_end = x_pos_start + bit_duration  # Kết thúc vị trí của bit
    axs[0].text((x_pos_start + x_pos_end) / 2, 6.5, bit, fontsize=12, ha='center', color='black')  # Thêm bit ở giữa

# Hình 2: Nhiễu ±0.5V và ±0.25V
axs[1].plot(time, noise, label='Noise ±0.5V Or Noise ±0.5V', color='red')
axs[1].set_title("Noise Signals (±0.5V and ±0.25V)")
axs[1].set_ylabel('Voltage Level (V)')
axs[1].set_ylim(-0.75, 0.75)
axs[1].grid()
axs[1].legend()

# Hình 3: Tín hiệu sau nhiễu
# Đảm bảo voltage_with_noise_05 và voltage_with_noise_025 được tính toán đúng
axs[2].step(time, voltage_with_noise, where='post', color='purple', label='With ±0.5V and ±0.25V Noise')
axs[2].set_title("NRZ-I Signal with Noise")
axs[2].set_ylabel('Voltage Level (V)')
axs[2].set_ylim(0, 7)
axs[2].grid()
axs[2].legend()

plt.tight_layout()
plt.show()