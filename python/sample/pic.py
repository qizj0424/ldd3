#-*- coding:utf-8 -*-
'''
v1.0:
基础图片处理工具，可实现镜像 旋转 划线
v2.0:
添加对话窗口更加人性化

'''
import sys
import tkinter as tk
import tkinter.messagebox #这个是消息框，对话框的关键
from tkinter.simpledialog import askstring, askinteger, askfloat
import os

from PIL import Image,ImageOps,ImageDraw
from tkinter import filedialog
from os import listdir

'''
def but():
    a=tkinter.messagebox.askokcancel('提示', '要执行此操作吗')
    print (a)
root=tkinter.Tk()
root.title('GUI')#标题
root.geometry('800x600')#窗体大小
root.resizable(False, False)#固定窗体
tkinter.Button(root, text='hello button',command=but).pack()
root.mainloop()
'''


'''打开选择文件夹对话框'''
root = tk.Tk()
root.withdraw()




#打开文件获取路径文件名
#Folderpath = filedialog.askdirectory() #获得选择好的文件夹
filename = filedialog.askopenfilename() #获得选择好的文件
#Allfilename = listdir(filename)     #所选文件夹下所有的文件名
save_dir,save_filename = os.path.split(filename)#获得路径与文件名
save_dir = save_dir+'\\'



im = Image.open(filename)

#打印图片基本信息
print(im)
print(im.format,im.size,im.mode)




#判断图像是否镜像
mirror=tkinter.messagebox.askokcancel('提示', '图片是否需要镜像？')
if mirror == True:
    print('图像镜像......')
    save_filename = 'mirrow_'+save_filename
    im = ImageOps.mirror(im)
    save_pic = tkinter.messagebox.askokcancel('提示', '是否需要保存镜像后的图片？')
    if save_pic == True:
        im.save(save_dir+save_filename)
    else:
        print('---取消保存---')
else:
    print('--图像保持--')




#判断图像是否旋转
rotate=tkinter.messagebox.askokcancel('提示', '图片是否需要旋转？')
rotate_angel = 180
if rotate == True:
    save_filename = 'rotate_'+save_filename
    
    tkinter.messagebox.showinfo('提示','请选择图像旋转角度：')
    def print_rotate_angel():
        global rotate_angel
        rotate_angel = int(askinteger("Spam", "angel", initialvalue=180))        
    def quit(root):
        root.quit()
    root = tk.Tk()
    tk.Button(root, text='旋转角度', command=print_rotate_angel).pack()
    tk.Button(root, text="  确定  ", command=lambda root=root:quit(root)).pack()
    root.mainloop()

    im = im.rotate(rotate_angel)

    save_pic=tkinter.messagebox.askokcancel('提示', '是否需要保存旋转后的图片？')
    if save_pic == True:
        im.save(save_dir+save_filename)
    else:
        print('---取消保存---')
else:
    print('--图像保持--')




#选择图片均分大小
average_x=15
average_y=15
num=tkinter.messagebox.askokcancel('提示', '是否选择图片分割大小？ 默认15x15')
if num == True:
    def print_integer_x():
        global average_x
        average_x = askinteger("Spam", "x", initialvalue=average_x)
    def print_integer_y():
        global average_y
        average_y = askinteger("Spam", "y", initialvalue=average_y)
    def quit(root):
        root.quit()
    root = tk.Tk()
    tk.Button(root, text='纵向分割大小', command=print_integer_x).pack()
    tk.Button(root, text='横向分割大小', command=print_integer_y).pack()
    tk.Button(root, text="  确定  ", command=lambda root=root:quit(root)).pack()
    root.mainloop()
else:
    average_x=15
    average_y=15





#计算坐标
im_x=int(im.size[0]/average_x)
im_y=int(im.size[1]/average_y)

num_x = int(im.size[0]/average_x)
num_y = int(im.size[1]/average_y)




#画线
draw = ImageDraw.Draw(im) #实例化一个对象
for num_x in range(num_x,im.size[0]-average_x+1,im_x):
    draw.line((num_x, 0)+(num_x,im.size[1]), fill=128, width=2)

for num_y in range(num_y,im.size[1]-average_x+1,im_y):
    draw.line((0, num_y)+(im.size[0],num_y), fill=128, width=2)


im.show()
im.save(save_dir+'cross_'+save_filename)


#if __name__ == ‘__main__‘:
#    main()
