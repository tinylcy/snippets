package main

import (
	"crypto"
	"crypto/rand"
	"crypto/rsa"
	"crypto/sha256"
	"fmt"
	"log"
)

func main() {

	// Generate RSA keys.
	privateKeyOne, err := rsa.GenerateKey(rand.Reader, 2048)
	if err != nil {
		log.Fatal(err)
	}
	publicKeyOne := &privateKeyOne.PublicKey

	privateKeyTwo, err := rsa.GenerateKey(rand.Reader, 2048)
	if err != nil {
		log.Fatal(err)
	}
	publicKeyTwo := &privateKeyTwo.PublicKey

	// fmt.Printf("Private Key 1: %v\n", privateKey1)
	// fmt.Printf("Public Key 1: %v\n", publicKey1)
	// fmt.Printf("Private Key 2: %v\n", privateKey2)
	// fmt.Printf("Public Key 2: %v\n", publicKey2)

	message := []byte("tinylcy")
	label := []byte("")
	hash := sha256.New()

	// EncryOAEP encrypts the given message with RSA-OAEP
	// OAEP is parameterised by a hash function that is used as a random oracle.
	// Encryption and decryption of a given message must use the same hash function
	// and sha256.New() is a reasoneble choice.
	//
	// The random parameter is used as a source of entropy to ensure that encrypting
	// the same message twice doesn't result in the same ciphertext.
	//
	// The label parameter may contain arbitrary data that will not be encrypted, but
	// which gives important context to the message.
	ciphertext, err := rsa.EncryptOAEP(hash, rand.Reader, publicKeyTwo, message, label)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("OAEP encrypted [%s] to \n[%x]\n", string(message), ciphertext)
	fmt.Println()

	// Message - Signature
	var opts rsa.PSSOptions
	opts.SaltLength = rsa.PSSSaltLengthAuto
	PSSmessage := message
	newhash := crypto.SHA256 // Hash function
	pssh := newhash.New()
	pssh.Write(PSSmessage)
	hashed := pssh.Sum(nil) // The result of hashing message

	// SignPSS calculates the signature of hashed using RSASSA-PSS.
	// Note that hashed must be the result of hashing the input message using the given hash function.
	signature, err := rsa.SignPSS(rand.Reader, privateKeyOne, newhash, hashed, &opts)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("PSS signature: %x\n", signature)

	plaintext, err := rsa.DecryptOAEP(hash, rand.Reader, privateKeyTwo, ciphertext, label)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("OAPE decrypted [%x] to \n [%s]\n", ciphertext, plaintext)

	err = rsa.VerifyPSS(publicKeyOne, newhash, hashed, signature, &opts)
	if err != nil {
		log.Fatal(err)
	} else {
		fmt.Println("Verify signature successful")
	}

}
