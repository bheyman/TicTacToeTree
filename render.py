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

im = Image.new("RGB", (500,500), "#fff");
draw = ImageDraw.Draw(im);

draw_board(0,0,draw, "012012012")
draw_board(100,100,draw, "000111222")

im.show()
