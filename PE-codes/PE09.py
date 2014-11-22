gotit = False
for x in range(1,1001,1):
    if gotit: break
    for y in range(1,1001,1):        
        if x+y < 10000:
            z = 1000 - x - y
            if x**2 + y**2 == z**2:
                print(x*y*z)
                gotit = True
        
    
