from Sloth.Message import Message
from Sloth.BinaryTypeDef import BinaryTypeDef
class GameModel:
    Easy = 0
    Normal = 1
    Hard = 2

class Skill:
    META = (
        ( BinaryTypeDef.UINT16, 'skill_id', ), 
        ( BinaryTypeDef.STRING, 'skill_name', ), 
        )
    def __init__(self):
        self.skill_id = 0
        self.skill_name = ''


class User(Message):
    META = (
        ( BinaryTypeDef.UINT16, 'a', ), 
        ( BinaryTypeDef.UINT32, 'b', ), 
        ( BinaryTypeDef.INT16, 'c', ), 
        ( BinaryTypeDef.INT32, 'd', ), 
        ( BinaryTypeDef.STRING, 'e', ), 
        ( BinaryTypeDef.FLOAT, 'f', ), 
        ( BinaryTypeDef.BOOL, 'g', ), 
        ( BinaryTypeDef.STRUCT, 'h', ), 
        ( BinaryTypeDef.LIST, 'i', BinaryTypeDef.UINT16, ), 
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
        self.i = list()




