from PIL import Image, ImageDraw, ImageFont

def draw_board(x,y, draw, state):

    draw.line([(x+25,y+0), (x+25,y+75)], fill="black")
    draw.line([(x+50,y+0), (x+50,y+75)], fill="black")

    draw.line([(x+0,y+25), (x+75,y+25)], fill="black")
    draw.line([(x+0,y+50), (x+75,y+50)], fill="black")

    for i in range(0,3):
        for j in range(0,3):
            if state[j*3+i] == '0':
                pass
            elif state[j*3+i] == '1':
                draw.text((x+25*i,y+25*j), "X", "black", align='center', anchor='mm')
            elif state[j*3+i] == '2':
                draw.text((x+25*i,y+25*j), "O", "black", align='center', anchor='mm')

file = open("temp.txt",'r')

lines = file.readlines()

turns = [[],[],[],[],[],[],[],[],[],[]]

for i in range(0,len(lines)//5):
    turn_num = lines[i*5+0].strip().split(" ")[1]
    board_num = lines[i*5+1].strip().split(" ")[1]
    board_state = lines[i*5+2].strip().split(" ")[2]
    if(lines[i*5+3].strip() == 'Children:'):
        children = []
    else:
        children = lines[i*5+3].strip().split(" ")[1].split(",")[0:-1]

    turns[int(turn_num)].append((board_state,children))

im = Image.new("RGB", (8000,20400), "#fff");
draw = ImageDraw.Draw(im);

for i in range(0,len(turns)):
    for j in range(0,len(turns[i])):
        draw_board(800*i,100*j,draw, turns[i][j][0])
        
        for k in range(0,len(turns[i][j][1])):

            #draw.line([(400*i+100,100*j+50),(400*(i+1),100*turns[i][j][1][k]+50)],fill='black', width=1)
            draw.line([(800*i+100,100*j+37),(800*(i+1)-25,100*int(turns[i][j][1][k])+37)],fill='black', width=1)

#im.show()

im.save("temp.jpg", quality=100)
