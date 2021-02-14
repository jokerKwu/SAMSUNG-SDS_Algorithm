stk = []

def rangeCheck(x):
    if 1000000000 >= abs(x):
        return True
    else: return False

def num(x):
    if len(stk) >= 1000 :
        return False
    stk.append(x)     
    return True
def pop():
    if len(stk) == 0:
        return False
    stk.pop()
    return True
def inv():
    if len(stk) == 0:
        return False
    tmp = stk[-1]
    stk[-1] = tmp * (-1)
    return True
def dup():
    if len(stk) == 0:
        return False
    tmp = stk[-1]
    stk.append(tmp)    
    return True

def swp():
    if len(stk) < 2:
        return False
    num1 = stk.pop()
    num2 = stk.pop()
    stk.append(num1)
    stk.append(num2)
    return True

def add():
    if len(stk) < 2:
        return False
    num1 = stk.pop()
    num2 = stk.pop()
    if(rangeCheck(num1 + num2) == True):
        stk.append(num1 + num2)
    else: return False
    return True

def sub():
    if len(stk) < 2:
        return False
    num1 = stk.pop()
    num2 = stk.pop()
    if(rangeCheck(num2 - num1) == True):
        stk.append(num2 - num1)
    else: return False
    return True

def mul():
    if len(stk) < 2:
        return False
    num1 = stk.pop()
    num2 = stk.pop()
    if(rangeCheck(num2 * num1) == True):
        stk.append(num2 * num1)
    else: return False

    return True

## 음수일때 0으로 나눌때 
def div():
    if len(stk) < 2:
        return False
    num1 = stk.pop()
    num2 = stk.pop()
    if num1 == 0:
        return False
    neg = 0
    if num1 < 0 or num2 < 0:
        res = abs(num2) // abs(num1)
        if num1 * num2 <= 0:
            res *= -1
        stk.append(res)
    else:
        stk.append(num2//num1)
    return True

def mod():
    if len(stk) < 2:
        return False
    num1 = stk.pop()
    num2 = stk.pop()
    if num1 == 0:
        return False
    if num1 < 0 or num2 < 0:
        res = abs(num2) % abs(num1)
        if num2 < 0:
            stk.append(-res)
        else:
            stk.append(res)
    else:
        stk.append(num2 % num1)
    return True

flag = False
while True:
    operator = []
    while True:
        oper = input()
        # END가 QUIT보다 먼저 적힌다면 END해서 break되면 밑에 QUIT로 가지 못함!!
        if oper == 'QUIT':
            flag = True
            break

        if oper == 'END':
            break

        operator.append(oper)
    if flag:
        break
    N = int(input())

    for i in range(N):
        stop = False
        n = int(input())
        stk.append(n)
        # [2, 7]에서 num_x로 스택의 가장 위에 저장하는 것이라면 num 8이면 [2, 7, 8]이 된다
        # 첫번째 숫자는 number.pop()할 때 나오는 것 -> 즉, 8!
        for o in operator:
            if o[:3] == 'NUM':
                a = int(o[4:])
                num(a)
            elif o[:3] == 'POP':
                if pop() == False:
                    stop = True
                    break
            elif o[:3] == 'INV':
                if inv() == False:
                    stop = True
                    break
            elif o[:3] == 'DUP':
                if dup() == False:
                    stop = True
                    break
            elif o[:3] == 'SWP':
                if swp() == False:
                    stop = True
                    break
            elif o[:3] == 'ADD':
                if add() == False:
                    stop = True
                    break
            elif o[:3] == 'SUB':
                if sub() == False:
                    stop = True
                    break
            elif o[:3] == 'MUL':
                if mul() == False:
                    stop = True
                    break
            elif o[:3] == 'DIV':
                if div() == False:
                    stop =True
                    break
            elif o[:3] == 'MOD':
                if mod() == False:
                    stop = True
                    break

        if stop or len(stk) != 1:
            print('ERROR')
        elif len(stk) == 1:
            print(stk[0])
        stk.clear()

    print()