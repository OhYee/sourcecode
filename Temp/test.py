	
def b(x,y):   
    if y<0 || y>x: 
        return 0 
    if x=0:
        [1$2],
      (p-> p+[0, p[1]])(b(x-1, y)+b(x, y-1)+b(x-1, y+1))))

a:= n-> b(n$2)[2]:
seq(a(n), n=0..30);