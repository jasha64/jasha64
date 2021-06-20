from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from PIL import Image
import numpy


class HanoiModel():
    def __init__(self):  # Here we pre-define some variables for later use.
        # window
        self.win_width = 400
        self.win_height = 400
        self.view = numpy.array([-0.8, 0.8, -0.8, 0.8, 1.0, 20.0])

        # camera
        self.eye = numpy.array([-0.75, 1.0, 1.5])
        self.eye_up = numpy.array([0.0, 1.0, 0.0])  # 视线方向法向(头顶朝哪儿)
        self.look_at = numpy.array([0.0, 0.0, -0.15])

        # vertex and texture coords (pre-define)
        self.vertexes = [[-0.5, -0.5, 0], [0.5, -0.5, 0], [0.5, 0.5, 0], [-0.5, 0.5, 0],
                         [-0.5, -0.5, -0.3], [0.5, -0.5, -0.3], [0.5, 0.5, -0.3], [-0.5, 0.5, -0.3]]
        self.tex_coords = [[0.0, 0.0], [1.0, 0.0], [1.0, 1.0], [0.0, 1.0],
                           [0.0, 0.0], [1.0, 0.0], [1.0, 1.0], [0.0, 1.0]]

    def init(self):
        # 画布初始化
        glClearColor(0.0, 0.0, 0.0, 1.0)  # 设置画布背景色(四个参数，分别RGBA)
        glEnable(GL_DEPTH_TEST)  # 开启深度测试，实现遮挡关系
        glDepthFunc(GL_LEQUAL)  # 深度测试函数 (see OpenGL reference: https://www.khronos.org/registry/OpenGL-Refpages/gl4/)

        # set texture
        img = Image.open("./Texture/Shanghai.jpg")
        # img_data = numpy.array(list(img.get_data()), dtype=numpy.uint8)
        img_data = numpy.asarray(img, dtype=numpy.uint8)

        self.texture_id = glGenTextures(1)
        glBindTexture(GL_TEXTURE_2D, self.texture_id)
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT)
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT)
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT)
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.size[0], img.size[1],
                     0, GL_RGB, GL_UNSIGNED_BYTE, img_data)
        # glEnable(GL_TEXTURE_2D)
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL)
        glBindTexture(GL_TEXTURE_2D, self.texture_id)

        # 光照
        glShadeModel(GL_SMOOTH)  # 阴影处理
        
        glLightfv(GL_LIGHT0, GL_DIFFUSE, [1.0,1.0,1.0,1.0])  # 光源0漫反射强度
        light_position = [-0.8, 0.8, 0, 1.0]
        glLightfv(GL_LIGHT0, GL_POSITION, light_position)  # 光源0位置
        
        glEnable(GL_LIGHTING)  # 打开光照
        glEnable(GL_LIGHT0)  # 打开光源0

    def draw(self):
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)  # 清除颜色及深度缓存。每次重绘之前都需调用。
        glMatrixMode(GL_MODELVIEW)

        # 汉诺塔三根柱子
        mat_diffuse = [233/255, 233/255, 216/255, 1.0] # 银色(RGBA, 每项范围[0, 1], 所以需要除以255)
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse)  # 设置物体正面(GL_FRONT)漫反射光颜色
        # glMaterialfv(GL_FRONT, GL_SHININESS, 1)
        
        glPushMatrix()
        glTranslated(-0.5, -0.25, 0)  # 平移
        glRotatef(270, 1, 0, 0)
        glutSolidCylinder(0.02, 1, 36, 1)  # 这个函数虽然名为圆柱，实际生成的却是棱柱，第三个参数就是有多少棱。只需设得足够大，就可以模拟圆柱效果。
        glTranslated(0.5, 0, 0)  # 在上面基础上，继续平移
        glutSolidCylinder(0.02, 1, 36, 1)
        glTranslated(0.5, 0, 0)
        glutSolidCylinder(0.02, 1, 36, 1)
        glPopMatrix()  # 恢复之前的矩阵状态，清除上面从PushMatrix()开始的所有旋转和平移
        
        # 汉诺塔三个圆盘
        mat_diffuse = [176/255, 110/255, 64/255, 1] # 铜色
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse)
        
        glPushMatrix()
        glTranslated(0.5, -0.17, 0)
        glRotatef(90, 1, 0, 0)
        glutSolidCylinder(0.24, 0.08, 36, 1)
        glTranslated(0, 0, -0.08)
        glutSolidCylinder(0.16, 0.08, 36, 1)
        glTranslated(0, 0, -0.08)
        glutSolidCylinder(0.08, 0.08, 36, 1)
        glPopMatrix()

        # 基座
        mat_diffuse = [255/255, 255/255, 0/255, 1] # 金色
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse)

        glPushMatrix()
        glTranslated(-0.75, -0.25, -0.25)
        points = [[0,0,0], [0,0,0.6], [1.5,0,0.6], [1.5,0,0]]
        glBegin(GL_QUADS)
        glTexCoord2f(0, 0)
        glVertex3fv(points[0])
        glTexCoord2f(0, 1)
        glVertex3fv(points[1])
        glTexCoord2f(1, 1)
        glVertex3fv(points[2])
        glTexCoord2f(1, 0)
        glVertex3fv(points[3])
        glEnd()
        points = [[0,0,0.6], [0,-0.1,0.6], [1.5,-0.1,0.6], [1.5,0,0.6]]
        glBegin(GL_QUADS)
        glVertex3fv(points[0])
        glVertex3fv(points[1])
        glVertex3fv(points[2])
        glVertex3fv(points[3])
        glEnd()
        points = [[0,0,0.6], [0,-0.1,0.6], [0,-0.1,0], [0,0,0]]
        glBegin(GL_QUADS)
        glVertex3fv(points[0])
        glVertex3fv(points[1])
        glVertex3fv(points[2])
        glVertex3fv(points[3])
        glEnd()
        glPopMatrix()

        glFlush()  # 立即显示
    
    def reshape(self, w, h):
        # set window
        self.win_width = max(1, w)
        self.win_height = max(1, h)
        glViewport(0, 0, self.win_width, self.win_height) # 设置在屏幕上的窗口大小，参数描述屏幕窗口四个角的坐标(以象素表示)

        # set PROJECTION
        glMatrixMode(GL_PROJECTION)  # 该函数指定哪一种矩阵为当前矩阵。GL_PROJECTION：后继的操作均在投影变换范围内。
        glLoadIdentity()  # 设置当前矩阵为单位矩阵

        # 设置平行投影
        #  参数是视景体的 left / right / bottom / top / near / far 六个面，
        #  此处"视景体"含义是使用何种大小方框(视景体)来截取图像，亦即视野范围，在此可视为窗口大小。
        if self.win_width > self.win_height:
            glOrtho(self.view[0] * self.win_width / self.win_height, self.view[1] * self.win_width / self.win_height,
                      self.view[2], self.view[3],
                      self.view[4], self.view[5])
        else:
            glOrtho(self.view[0], self.view[1],
                      self.view[2] * self.win_height / self.win_width, self.view[3] * self.win_height / self.win_width,
                      self.view[4], self.view[5])

        # set MODELVIEW
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()
        
        # set camera
        gluLookAt(
            self.eye[0], self.eye[1], self.eye[2],
            self.look_at[0], self.look_at[1], self.look_at[2],
            self.eye_up[0], self.eye_up[1], self.eye_up[2]
        )


def main():
    graph = HanoiModel()

    glutInit()
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH)  # 初始化显示模式：RGBA(RGB+透明度)、单缓存模式、使用深度缓冲
    glutInitWindowSize(400, 400)
    glutInitWindowPosition(200, 200)
    glutCreateWindow("Hanoi Model")

    graph.init()
    glutDisplayFunc(graph.draw)  # 注册显示函数
    glutReshapeFunc(graph.reshape)  # 注册窗口大小改变时的响应函数
    glutMainLoop()


if __name__ == '__main__':
    main()
