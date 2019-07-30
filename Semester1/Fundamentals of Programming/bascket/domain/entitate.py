'''
Created on 12 feb. 2019

@author: Edy
'''

class Jucator(object):
    '''
    Un jucator de baschet
    '''


    def __init__(self, nume, prenume, inaltime, post):
        '''
        Constructor
        :param nume: numele jucatorului 
        :param prenume: prenumele jucatorului
        :param inaltime: inaltimea jucatorului
        :param post: postul care fi : extrema, etc;
        '''
        self.nume = nume
        self.prenume = prenume
        self.inaltime = inaltime
        self.post = post

    
    def getNume(self):
        '''
        get pentru nume
        '''
        return self.nume

    
    def getPrenume(self):
        '''
        get pentru prenume
        '''
        return self.prenume
    
    def setInaltime(self, inaltime):
        self.inaltime = inaltime
    
    def getInaltime(self):
        '''
        get pentru inaltime
        '''
        return self.inaltime

    
    def getPost(self):
        '''
        get pentru post
        '''
        return self.post
    
    def __str__(self):
        text =""
        text += self.getNume() + "  " + self.getPrenume() + "  "+ str(self.getInaltime()) + "  "+self.getPost()+"\n"
        return text
    
    def __eq__(self, other):
        if self.getNume() == other.getNume() and self.getPrenume() == other.getPrenume():
            return True
        return False
    

def testJucator():
    '''
    testez entitatea
    '''
    jucator1 = Jucator("mihai","ion",130,"Fundas")
    assert jucator1.getNume() == "mihai"
    assert jucator1.getPrenume() == "ion"
    assert jucator1.getInaltime() == 130
    assert jucator1.getPost() == "Fundas"
    jucator2 = Jucator("mihai","ion",17,"Fundas")
    assert jucator1 == jucator2
    jucator3 = Jucator("bulan","bulan",120,"Pivot")


testJucator()

    
    