Easier way to Kuberentes secret hashing
============================================

## Usage

Instead of using usual base64 coding:

	echo -n "mysecretvalue" | base64

hashsc simplifies this to:

	hashsc "mysecretvalue"

although you still can use it the old way, so that hashsc is won't break compatibility wiht base64:

    echo -n "mysecretvalue" | hashsc

## Even more features

### Handling multiline inputs

With hashsc you can echo multiple strings to encode into secrets:

        $ echo "secret1\nsecret2" | hashsc --ml
        c2VjcmV0MQ==
        c2VjcmV0Mg==

base64 will give you one output of whole string:

        $ echo "secret1\nsecret2" | base64
        c2VjcmV0MQpzZWNyZXQyCg==

still you can use hashsc style for usability (position of --ml is not stricted to start of command):

    $ hashsc --ml "secret1\nsecret2"
    c2VjcmV0MQ==
    c2VjcmV0Mg==

## Limitations

hashsc currently doesn't support decoding, even though it is simple feature, it wasn't included in this release.
Please star to catalyse this project, or even better, contribute to it.

## Next releases

### 0.6

- Decoding of base64
- Multiline support for decoding
- Multiline custom delimiter support

### 0.7-0.8

- Output in different formats e.g JSON, XML, YAML
- Key-value output into formats
- Key supply for values

### 0.9

- Generation of Kubernetes secret from key-value inputs

### 1.0

- Decoding from Kubernetes secret file
- Commenting secret hashes with decoded value

## Profit for zsh users

If you're using zsh, hashsc can be faster called with hsc and then TAB.
