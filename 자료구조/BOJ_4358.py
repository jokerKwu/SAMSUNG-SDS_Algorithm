
date = {}
cnt = 1
while True:
    try:
        s = str(input())
        if s in date:
            date[s] += 1
        else:
            date[s] = 1
        cnt += 1
    except:
        break

for key, value in sorted(date.items()):
    n = float(value)/float(cnt)
    print('%s %.4f' % (key, (n * 100)))


'''
Ash 13.7931
Aspen 3.4483
Basswood 3.4483
Beech 3.4483
Black Walnut 3.4483
Cherry 3.4483
Cottonwood 3.4483
Cypress 3.4483
Gum 3.4483
Hackberry 3.4483
Hard Maple 3.4483
Hickory 3.4483
Pecan 3.4483
Poplan 3.4483
Red Alder 3.4483
Red Elm 3.4483
Red Oak 6.8966
Sassafras 3.4483
Soft Maple 3.4483
Sycamore 3.4483
White Oak 10.3448
Willow 3.4483
Yellow Birch 3.4483

'''