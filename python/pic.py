#-*- coding:utf-8 -*-
'''

'''
import sys
from PIL import Image,ImageOps,ImageDraw

#选择图片均分大小
average_x=15
average_y=15

filename=raw_input('enter a filename:').strip()#选择一张图片
im = Image.open(filename)

#打印图片基本信息
print(im)
print(im.format,im.size,im.mode)

#计算坐标
im_x=im.size[0]/average_x
im_y=im.size[1]/average_y

num_x = im.size[0]/average_x
num_y = im.size[1]/average_y

#画线
draw = ImageDraw.Draw(im) #实例化一个对象
for num_x in range(num_x,im.size[0]-average_x+1,im_x):
    draw.line((num_x, 0)+(num_x,im.size[1]), fill=128, width=2)
#    print(num_x)
for num_y in range(num_y,im.size[1]-average_x+1,im_y):
    draw.line((0, num_y)+(im.size[0],num_y), fill=128, width=2)
#    print(num_y)


#print(num)
#draw.line((0, 0) + im.size, fill=128, width=5)  #线的起点和终点，线宽
#draw.line((0, im.size[1], im.size[0], 0), fill=128)
#draw.line((0,im.size[1]/2)+(im.size[0]/2,im.size[1]), fill=128, width=5)

im.show()
im.save('cross_'+filename)
#im.save('filename.jpg')

'''
# 做镜面转换
im_mirror = ImageOps.mirror(im)
# 保存镜像图片
im_mirror.save('mirrow.png')
'''
