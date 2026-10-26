
from Crypto.PublicKey import RSA #importing libraries
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Hash import SHA256
from docx import Document
import struct

# Load RSA private key 
with open("private.pem", "rb") as file:
    private_key = RSA.import_key(file.read())


cipher = PKCS1_OAEP.new(private_key, hashAlgo=SHA256)

# Read encrypted file
with open("encrypted.bin", "rb") as file:
    chunk_count = struct.unpack(">I", file.read(4))[0]

    decrypted_data = bytearray()

    for _ in range(chunk_count):
        chunk_length = struct.unpack(">H", file.read(2))[0]
        encrypted_chunk = file.read(chunk_length)

        decrypted_data.extend(cipher.decrypt(encrypted_chunk))

# Convert bytes back into text
text = decrypted_data.decode("utf-8")

# Create recovered Word document
document = Document()

#add back the spaces and linebreaks
for paragraph in text.split("\n"):
    document.add_paragraph(paragraph)

document.save("decrypted.docx")

print("RSA decryption successful!")
print("Created decrypted.docx")
