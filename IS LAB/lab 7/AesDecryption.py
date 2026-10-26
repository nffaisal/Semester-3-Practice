
# Import libraries for Excel and AES decryption
from openpyxl import load_workbook
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad

# All hexadecimal digits (0-9 and a-f)
HEX = "0123456789abcdef"

# Store the encrypted roll number and name
data = {
    "Roll No": "8508c1a6018e9d02edcea90335e048d3",
    "Name": "47d10ff41b1b44e2435dfc41b49965f9"
}

# Read candidate keys from Excel, skipping the header row
sheet = load_workbook(
    r"D:\Semester 3 Practice\IS LAB\lab 7\ENC_KEYS.xlsx"
).active
keys = [row[0] for row in sheet.iter_rows(min_row=2, values_only=True)]


# Reverse a Caesar shift applied to hexadecimal digits
def unshift(key, shift):
    result = ""
    for ch in key:
        # Convert the hex digit to a number, shift backward, and wrap around
        shifted =(HEX.index(ch) - shift) % 16
        result += HEX[shifted]
    return result


# Decrypt the ciphertext using the given AES key
def decrypt(ciphertext, key):
    cipher = AES.new(key, AES.MODE_ECB)  # Create AES cipher in ECB mode
    encrypted = bytes.fromhex(ciphertext)  # Convert ciphertext from hex to bytes
    plain = unpad(cipher.decrypt(encrypted), 16)  # Decrypt and remove padding
    return plain.decode()  # Convert plaintext bytes to readable text


# Try each encrypted item
for label, ciphertext in data.items():

    # Try every candidate key from Excel
    for i, key in enumerate(keys, 1):

        # Try all 16 possible hexadecimal shifts (0-15)
        for shift in range(16):
            try:
                # Reverse the shift to generate a possible AES key
                candidate = unshift(key, shift)

                # Convert the hexadecimal key into bytes
                key_bytes = bytes.fromhex(candidate)
                # Attempt to decrypt the ciphertext
                text = decrypt(ciphertext, key_bytes)

                # Print the result if it contains printable characters
                if text.isprintable():
                    print(label, "=", text)
                    print("Key number:", i, "Shift:", shift)

            # Ignore failed attempts and continue trying other keys
            except (ValueError, UnicodeDecodeError):
                continue
