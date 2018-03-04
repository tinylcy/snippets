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

	cipherText, err := rsa.EncryptOAEP(hash, rand.Reader, publicKeyTwo, message, label)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("OAEP encrypted [%s] to \n[%x]\n", string(message), cipherText)
	fmt.Println()

	// Message - Signature
	var opts rsa.PSSOptions
	opts.SaltLength = rsa.PSSSaltLengthAuto
	PSSmessage := message
	newhash := crypto.SHA256
	pssh := newhash.New()
	pssh.Write(PSSmessage)
	hashed := pssh.Sum(nil)

	signature, err := rsa.SignPSS(rand.Reader, privateKeyOne, newhash, hashed, &opts)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("PSS signature: %x\n", signature)

	plainText, err := rsa.DecryptOAEP(hash, rand.Reader, privateKeyTwo, cipherText, label)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("OAPE decrypted [%x] to \n [%s]\n", cipherText, plainText)

	err = rsa.VerifyPSS(publicKeyOne, newhash, hashed, signature, &opts)
	if err != nil {
		log.Fatal(err)
	} else {
		fmt.Println("Verify signature successful")
	}

}
