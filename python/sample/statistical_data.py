# -*- coding:UTF-8 -*-
'''
运行环境:linux+python2.7
运行结果:用于统计某个文件单词出现次数，并绘制直方图
'''
#引入turtle模块，用于绘制结果图
import turtle

#全局变量
#词频排列显示个数，我们只显示出现次数最多的11个单词
count=11
#单词频率数组--作为y轴数据
numbers=[]
#单词数组--作为x轴数据
words=[]
#y轴显示放大倍数--可以根据词频数量进行调节
yScale=15
#x轴放大倍数--可以根据count数量进行调节
xScale=36


#Turtle Start
#从点(x1,y1)到(x2,y2)绘制线段
def drawLine(t,x1,y1,x2,y2):
    t.penup()
    t.goto(x1,y1)
    t.pendown()
    t.goto(x2,y2)


#在坐标(x,y)处写文字
def drawText(t,x,y,text):
    t.penup()
    t.goto(x,y)
    t.pendown()
    t.write(text)


def drawGraph(t):
    #绘制x/y轴线
    print(t)
    drawLine(t,0,0,420,0)
    drawLine(t,0,280,0,0)
    #x轴：坐标及描述
    for x in range(count):
        x=x+1#向右移一位，为了不画在原点上
        drawText(t,x*xScale-5,-16,words[x-1])
        drawText(t,x*xScale-3,numbers[x-1]*yScale+2,numbers[x-1])
    drawBar(t)


#绘制一个柱体
def drawRectangle(t,x,y):
    x=x*xScale
    y=y*yScale#放大倍数显示
    drawLine(t,x-8,0,x-8,y)
    drawLine(t,x-8,y,x+8,y)
    drawLine(t,x+8,y,x+8,0)
    #drawLine(t,x+8,0,x-8,0)
#绘制多个柱体
def drawBar(t):
    for i in range(count):
        drawRectangle(t,i+1,numbers[i])
#Turtle End
        
#处理文本的每一行,计算每一行的词频
def processLine(line,wordCounts):
    #用空格替换标点符号
    line=replacePunctuations(line)
    #从每一行获取每个词
    words=line.split()
    for word in words:
        if word in wordCounts:
            wordCounts[word]+=1
        else:
            wordCounts[word]=1


#用空格替换掉标点符号
def replacePunctuations(line):
    for ch in line:
        if ch in '~@#$%^()_-+=<>?/,.:;{}[]|""':
            line=line.replace(ch,' ')
    return line


def main():
    #用户输入一个文件名
    filename=raw_input('enter a filename:').strip()
    f=open(filename,'r')


    #建立用于计算词频的空字典,单词为键，出现次数为值
    wordCounts={}
    #处理文本中的每一行
    for line in f:
        processLine(line.lower(),wordCounts)


    #从字典中获取数据对
    pairs=list(wordCounts.items())
    #列表中的数据对交换位置，数据对排序
    items=[[x,y] for (y,x) in pairs]
    items.sort()#按照单词出现次数排序（由小到大）


    #输出最大的count个词频结果（列表中最后count个元素最大）
    for i in range(len(items)-1,len(items)-count-1,-1):
        print(items[i][1]+'\t'+str(items[i][0]))
        numbers.append(items[i][0])
        words.append(items[i][1])
    f.close()
    
    #根据词频结果绘制柱状图
    turtle.title('词频结果柱状图')
    turtle.setup(1200,750,0,0)
    t=turtle.Turtle()
    t.color('red')
    t.hideturtle()
    t.width(2)
    drawGraph(t)
    ts = turtle.getscreen()
    ts.getcanvas().postscript(file="./pic.eps")

#调用main()函数
if __name__=='__main__':
    main()
