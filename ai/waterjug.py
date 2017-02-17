storage = []

def push_stack(state):
    global stack
    stack.append(state)

def pop_stack():
    global stack
    value = stack.pop()
    return value
    

jug1_size = 4
jug2_size = 3

# in jug 2 water 2 L
final_state = [2, 2]

def check_final(cur_state, final_state):
    if cur_state[final_state[0] - 1] == final_state[1]:
        return True
    else:
        return False

current_state = [0,0]

def generate_state(current):
    global jug1_size
    global jug2_size
    jug1 = current[0]
    jug2 = current[1]
    
    # fil jug 1
    if jug1 < jug1_size:
        jug1 = jug1_size
        
        

#jug1 = int(raw_input("Enter size of first jug:"))
#jug2 = int(raw_input("Enter size of second jug:"))
#jug = int(raw_input("Enter which you want water in the end ? (1 or 2) : "))
#water = int(raw_input("How mush water you want in the end ? : "))

initial_state = [0,0]
final_state = [jug, water]

# [[state], parent]
search_space = []

current_state = initial_state
# push initial state to stack

while current_state != final_state:
    
