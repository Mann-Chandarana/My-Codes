from cryptography.hazmat.primitives.asymmetric import rsa, padding
from cryptography.hazmat.primitives import serialization, hashes

# Generating private and public keys

private_key = rsa.generate_private_key(public_exponent=65537,key_size=2048)
public_key = private_key.public_key()

# Signing the message with private key

message = b"This is a sample message to be signed."
signature = private_key.sign(message,padding.PSS(mgf=padding.MGF1(hashes.SHA256()),salt_length=padding.PSS.MAX_LENGTH),hashes.SHA256())

# Verifying the message with public key

try:
   public_key.verify(signature,message,padding.PSS(mgf=padding.MGF1(hashes.SHA256()),salt_length=padding.PSS.MAX_LENGTH),hashes.SHA256())
   print("The signature is valid.")
except:
   print("The signature is invalid.")
