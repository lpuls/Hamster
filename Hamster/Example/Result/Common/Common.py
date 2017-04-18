from Sloth.Message import Message
from Sloth.BinaryTypeDef import BinaryTypeDef

class PlayerJob:
    Brave = 0
    Swordman = 1
    Pastor = 2
    Wizard = 3


class Player:
    META = (
        ( BinaryTypeDef.UINT16, 'level',  ), 
        ( BinaryTypeDef.STRING, 'name',  ), 
        )
    def __init__(self):
        self.level = 0
        self.name = ''



class NotifyPlayerInfo (Message):
    META = (
        ( BinaryTypeDef.STRUCT, 'player',  ), 
        ( BinaryTypeDef.LIST, 'items', BinaryTypeDef.UINT32 ), 
        ( BinaryTypeDef.UINT32, 'money',  ), 
        ( BinaryTypeDef.UINT32, 'soul',  ), 
        )
    MID = 3
    def __init__(self):
        self.player = Player()
        self.items = list()
        self.money = 0
        self.soul = 0




