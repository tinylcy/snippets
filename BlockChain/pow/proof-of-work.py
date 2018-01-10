# Example of proof-of-work algorithm

import hashlib
import time

max_nonce = 2 ** 32

def proof_of_work(header, difficulty_bits):
    # Calculate the difficulty target
    target = 2 ** (256 - difficulty_bits)

    for nonce in range(max_nonce):
        hash_result = hashlib.sha256((str(header) + str(nonce)).encode("utf-8")).hexdigest()

        # Check if this is a valid result, below the target
        if int(hash_result, 16) < target:
            print("Success with nonce ", nonce)
            print("Hash is ", hash_result)
            return (hash_result, nonce)

    print("Failed after {} (max_nonce) tries".format(nonce))
    return nonce

if __name__ == "__main__":
    nonce = 0
    hash_result = ''

    # Difficulty from 0 to 31 bits
    for difficulty_bits in range(32):
        difficulty = 2 ** difficulty_bits
        print("Difficulty: {} ({} bits)".format(difficulty, difficulty_bits))
        print("Start searching...")

        # Checkpoint the current time
        start_time = time.time()
        
        # Make a new block which includes the hash from the previous block
        # We fake a block of transactions - just a string
        new_block = "test block with transactions" + hash_result

        # Find a valid nonce for the new block
        (hash_result, nonce) = proof_of_work(new_block, difficulty_bits)

        # Checkpoint how long it took to find a result
        end_time = time.time()

        elapsed_time = end_time - start_time
        print("Elapsed Time: {} seconds".format(elapsed_time))

        if elapsed_time > 0:
            # Estimate the hashed per second
            hash_power = float(int(nonce) / elapsed_time)
            print("Hashing Power: {} hashed per second".format(hash_power))
