r = 10
x = 0
y = r
p = 1 - r

while (x <= y):
	print "(%d, %d)" % (x, y)
	if(p < 0):
		#print "Calculating using x : " + str(x)
		p = p + 2 * x + 3
		print "p is " + str(p)
	else:
		#print "Calculating using x : " + str(x) + " and y : " + str(y) 
		p = p + 2 * (x - y) + 5
		print "p is " + str(p)
		y = y - 1
	x = x + 1