# import System

class Skill:
    def __init__(self):
        pass

class User(Message):
    META = (
        ( BinaryTypeDef.UINT16, a, ), 
        ( BinaryTypeDef.UINT32, b, ), 
        ( BinaryTypeDef.INT16, c, ), 
        ( BinaryTypeDef.INT32, d, ), 
        ( BinaryTypeDef.STRING, e, ), 
        ( BinaryTypeDef.FLOAT, f, ), 
        ( BinaryTypeDef.BOOL, g, ), 
        ( BinaryTypeDef.STRUCT, h, ), 
        )
    MID = 2
    def __init__(self):
        self.a = 0
        self.b = 0
        self.c = 0
        self.d = 0
        self.e = ''
        self.f = 0.0
        self.g = True
        self.h = Skill()

if __name__ == '__main__':
    user = User()
    print(user.a)




