
from Crypto.PublicKey import RSA #importing all required libraries
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Hash import SHA256
from docx import Document
import struct
# Read text from the Word document
from pathlib import Path

# Get the folder containing encrypt.py
BASE_DIR = Path(__file__).resolve().parent

# Locate input.docx in that folder
document = Document(BASE_DIR / "input.docx")
text = "\n".join(paragraph.text for paragraph in document.paragraphs)

# Convert text into bytes
data = text.encode("utf-8")

# Load RSA public key
with open("public.pem", "rb") as file:
    public_key = RSA.import_key(file.read())

# RSA-OAEP with SHA-256 and a 2048-bit key
cipher = PKCS1_OAEP.new(public_key, hashAlgo=SHA256)

# Maximum plaintext chunk size: 190 bytes for RSA-2048/SHA-256
chunk_size = 190
encrypted_chunks = []

for i in range(0, len(data), chunk_size):
    chunk = data[i:i + chunk_size]
    encrypted_chunks.append(cipher.encrypt(chunk))

# Save encrypted chunks with their lengths
with open("encrypted.bin", "wb") as file:
    file.write(struct.pack(">I", len(encrypted_chunks)))

    for chunk in encrypted_chunks:
        file.write(struct.pack(">H", len(chunk)))
        file.write(chunk)

#show succesful creation message
print("RSA encryption successful!")
print("Created encrypted.bin")
