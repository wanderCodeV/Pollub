import math
import turtle

def FractalLine(x1,y1,x2,y2):
    turtle.penup()
    turtle.goto(x1,y1)
    turtle.pendown()
    turtle.goto(x2,y2)
def Fractal(x,y,angleBase,length,color,depth,maxDepth):
    if depth>maxDepth:
        return

    turtle.pencolor(color)

    angleNew = angleBase-(math.pi/8)
    xEnd = x + math.cos(angleNew)*length
    yEnd = y + math.sin(angleNew)*length
    FractalLine(x,y,xEnd,yEnd)
    Fractal(xEnd,yEnd,angleNew,length*.75,color,depth+1,maxDepth)

    angleNew = angleBase+(math.pi/8)
    xEnd = x + math.cos(angleNew)*length
    yEnd = y + math.sin(angleNew)*length
    FractalLine(x,y,xEnd,yEnd)
    Fractal(xEnd,yEnd,angleNew,length*.75,color,depth+1,maxDepth)
    
turtle.speed('fastest')
turtle.Screen().bgcolor("black")
Fractal(x=-100,y=-100,angleBase=math.pi/2,length=100,color='cyan',depth=0,maxDepth=8)


turtle.done()
