def rsa_encrypt_chunked(M, e, n):
    # Convert message M to string, then split it into smaller chunks
    M_str = str(M)
    chunk_size = len(str(n)) - 1  # Ensure chunk size is smaller than n
    chunks = [int(M_str[i:i + chunk_size]) for i in range(0, len(M_str), chunk_size)]

    # Encrypt each chunk
    encrypted_chunks = [pow(chunk, e, n) for chunk in chunks]
    return encrypted_chunks

def rsa_decrypt_chunked(encrypted_chunks, d, n):
    # Decrypt each chunk
    decrypted_chunks = [pow(chunk, d, n) for chunk in encrypted_chunks]

    # Reassemble the decrypted message
    decrypted_message = ''.join(str(chunk) for chunk in decrypted_chunks)
    return int(decrypted_message)

# Given values (adjust these based on your actual RSA setup)
M = 6882326879666683  # Original message (plaintext)
e = 79                # Public exponent
d = 1019              # Private exponent
n = 3337              # Modulus (this must be correct and larger than chunks)

# Encrypt the message in chunks
encrypted_chunks = rsa_encrypt_chunked(M, e, n)
print("Encrypted Chunks:", encrypted_chunks)

# Decrypt the encrypted chunks
M_decrypted = rsa_decrypt_chunked(encrypted_chunks, d, n)
print("Decrypted Text (M):", M_decrypted)

# Check if the decryption matches the original message
if M_decrypted == M:
    print("Decryption successful!")
else:
    print("Decryption failed. The result doesn't match the original message.")
