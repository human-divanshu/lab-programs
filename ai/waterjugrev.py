l = []

def stackpush(s):
	l.append(s)
	
def stackpop():
	return l.pop()

def stackempty():
	return len(l) == 0

def queueempty():
	return len(l) == 0

def queue(s):
	l.append(s)
	
def dequeue():
	global l
	item = l[0]
	l = l[1:]
	return item

def isfinal(indexofs):
	global matchcount
	matchcount = matchcount + 1
	j1 = indexofs / (jug2size + 1)
	j2 = indexofs % (jug2size + 1)
	return (j1 == 0) and (j2 == 0)

def decodestate(indexofs):
	j1 = indexofs / (jug2size + 1)
	j2 = indexofs % (jug2size + 1)
	return j1, j2

def codestate(j1, j2):
	return (jug2size + 1) * j1 + j2

def isvisited(indexofs):
	return searchspace[indexofs][0] == 1
	

def addstate(j1, j2, parent):
	stateindex = codestate(j1, j2)
	if searchspace[stateindex][0] == 1:
		print "Ignoring " + str(j1) + ", " + str(j2)
	else:
		print "Adding : " + str(j1) + ", " + str(j2)
		searchspace[stateindex] = [1, parent]
		l.append(codestate(j1, j2))

def generatestate(indexofs):
	global statesmade
	j1, j2 = decodestate(indexofs)
	#empty 1
	if j1 == jug1size:
		statesmade = statesmade + 1
		print "Empty 1"
		addstate(0, j2, indexofs)
	#empty 2
	if j2 == jug2size:
		statesmade = statesmade + 1
		print "Empty 2"
		addstate(j1, 0, indexofs)
	# pour j1 to j2
	if j1 != 0:
		statesmade = statesmade + 1
		print "Pour j1 to j2"
		topour = min(j1, jug2size - j2)
		newj1 = j1 - topour
		newj2 = j2 + topour
		addstate(newj1, newj2, indexofs)
	# pour j2 to j1
	if j2 != 0:
		statesmade = statesmade + 1
		print "j2 to j1"
		topour = min(j2, jug1size - j1)
		newj2 = j2 - topour
		newj1 = j1 + topour
		addstate(newj1, newj2, indexofs)
	# fill j1
	if j1 < jug1size:
		statesmade = statesmade + 1
		print "fill j1"
		addstate(jug1size, j2, indexofs)
	# fill j2
	if j2 < jug2size:
		statesmade = statesmade + 1
		print "fill j2"
		addstate(j1, jug2size, indexofs)
	
	

def backtrack(indexofs):
	cur = indexofs
	ans = []
	while cur != 0:
		j1, j2 = decodestate(cur)
		ans.append([j1, j2])
		cur = searchspace[cur][1]
	ans.append([0,0])
	ans.reverse()
	print ans

def bfs():
	flag = True
	while flag or len(l) == 0:
		tstate = dequeue()
		print "Processing : state : " + str(tstate) + " : " + str(decodestate(tstate))
		if isfinal(tstate):
			backtrack(tstate)
			flag = False
		else:
			generatestate(tstate)
	if flag:
		print "No possible solution"
		
	
#jug1size = 5
#jug2size = 3
#finalwater = 4

jug1size = int(raw_input("Enter size of jug 1:"))
jug2size = int(raw_input("Enter size of jug 2:"))
finalwater = int(raw_input("Enter amount of water in final state :"))


# counters
statesmade = 0
matchcount = 0

# ask to choose algo here
algo = 0 # for bfs - queue implementation

searchspace = [] # [x, y] as item where x will tell if already generated or not
# and y will tell about parent state


for i in range(0, ((jug1size + 1) * (jug2size + 1))):
	searchspace.append([0,0])
searchspace[0] = [1,-1]	# because no one is parent of initial state

#print searchspace

istate = finalwater # initial state

if algo == 0:
	queue(istate)
	bfs()
else:
	stackpush(istate)
	dfs()

print "Statemade = " + str(statesmade)
print "matchcount = " + str(matchcount)