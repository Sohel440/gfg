import pyseal
import numpy as np

# Create a SEAL context
context = pyseal.Context()

# Generate keys
public_key, secret_key = context.keygen()

# Create an encoder
encoder = pyseal.Encoder(context)

# Encryptor and decryptor
encryptor = pyseal.Encryptor(context, public_key)
decryptor = pyseal.Decryptor(context, secret_key)

# Create plaintexts
plain1 = np.array([5])
plain2 = np.array([3])

# Encode plaintexts
encoded_plain1 = encoder.encode(plain1)
encoded_plain2 = encoder.encode(plain2)

# Encrypt plaintexts
encrypted_plain1 = encryptor.encrypt(encoded_plain1)
encrypted_plain2 = encryptor.encrypt(encoded_plain2)

# Perform homomorphic addition
encrypted_sum = encrypted_plain1 + encrypted_plain2

# Decrypt and decode the result
decrypted_sum = decryptor.decrypt(encrypted_sum)
decoded_sum = encoder.decode(decrypted_sum)

print("5 + 3 =", decoded_sum[0])
