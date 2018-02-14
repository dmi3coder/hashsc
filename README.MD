Easier way to Kuberentes secret hashing
============================================

## Usage

Instead of using usual base64 coding:

	echo -n "mysecretvalue" | base64

hashsc simplifies this to:

	hashsc "mysecretvalue"

## Even more features

### Handling multiline inputs

With hashsc you can echo multiple strings to encode into secrets:

        $ echo "secret1\nsecret2" | hashsc --ml
        c2VjcmV0MQ==
        c2VjcmV0Mg==

base64 will give you one output of whole string:

        $ echo "secret1\nsecret2" | base64
        c2VjcmV0MQpzZWNyZXQyCg==
