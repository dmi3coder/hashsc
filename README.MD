Easier way to Kuberentes secret hashing
============================================

## Usage

Instead of using usual base64 coding:

	echo -n "mysecretvalue" | base64

hashsc simplifies this to:

	hashsc "mysecretvalue"

