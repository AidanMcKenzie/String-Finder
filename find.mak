findmak:
	cl find.c
	find "Boba Fett" -i empire.txt -o boba.txt
	find footloose -i footloose.txt -c
	find obama -i snowden.txt -o obama.txt -c

	cl find.c