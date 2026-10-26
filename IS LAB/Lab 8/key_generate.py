
from Crypto.PublicKey import RSA

# Generate a 2048-bit RSA key pair
key = RSA.generate(2048)

# Save the private key
with open("private.pem", "wb") as file:
    file.write(key.export_key(format="PEM", passphrase=None))

# Extract and save the public key
public_key = key.publickey()

#write public key to the public.pem
with open("public.pem", "wb") as file: 
    file.write(public_key.export_key(format="PEM"))


#send message of completing successfully
print("RSA keys generated successfully!")
print("Created private.pem and public.pem")
