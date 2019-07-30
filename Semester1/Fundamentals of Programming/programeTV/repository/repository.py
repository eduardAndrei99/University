from domain.entitati import Emisiune
import random

class RepoError(Exception):
    pass

class RepositoryEmisiune():
    
    def __init__(self, numeFisier):
        self.numeFisier = numeFisier
        self.programeBlocate = ""
        
    def getEmisiuni(self):
        '''
        returnez o lista cu emisiunile din fisier
        '''
        emisiuni = []
        try:
            fisier = open(self.numeFisier)
        except IOError as ex:
            print("Nu s a deschis")
            return
        
        linie = fisier.readline().strip()
        while linie != "":
            
            delimitator = linie.split(",")
            emisiune = Emisiune(delimitator[0],delimitator[1],delimitator[2],delimitator[3])
            emisiuni.append(emisiune)
            linie = fisier.readline().strip()
        return emisiuni  
    
    def store(self, listaEmisiuni):
        '''
        salvez lista de emisiuni in fisier
        '''
        with open(self.numeFisier, "w") as fisier:
            for emisiune in listaEmisiuni:
                text =""
                text += emisiune.getNume()
                text += ","
                text += emisiune.getTip()
                text += ","
                text += str(emisiune.getDurata())
                text += ","
                text += emisiune.getDescriere()
                text += "\n"
                fisier.write(text)
    
    
    def stergEmisiune(self, nume, tip):
        '''
        sterg emisiunea daca exista
        '''
        
        toateEmisiunile = self.getEmisiuni()
        listaNoua = []
        emisiuneDeCautat = Emisiune(nume,tip,1,"dsa")
        if tip in self.programeBlocate:
            raise RepoError

        for emisiune in toateEmisiunile:
            if  not (emisiune.getNume() == emisiuneDeCautat.getNume() and emisiune.getTip() == emisiuneDeCautat.getTip()):
                listaNoua.append(emisiune)
        if len(listaNoua) ==len(toateEmisiunile):
            raise RepoError
        self.store(listaNoua)
    
    def cateEmisiuni(self):
        '''
        returnez cate emisiuni sunt in fisier
        '''
        return len(self.getEmisiuni())
    
        
    def actualizezEmisiune(self, nume, tip, durata, descriere):
        '''
        actualizez emisiune
        '''
        toateEmisiunile = self.getEmisiuni()
        gasit = False
        listaNoua = []
        emisiuneDeCautat = Emisiune(nume,tip,durata,descriere)
        if tip in self.programeBlocate:
                raise RepoError
        for emisiune in toateEmisiunile:
            if  emisiune.getNume() == emisiuneDeCautat.getNume() and emisiune.getTip() == emisiuneDeCautat.getTip():
                gasit = True
                listaNoua.append(emisiuneDeCautat)
            else:
                listaNoua.append(emisiune)
        self.store(listaNoua)
        if gasit == False:
            raise RepoError
        
        
    def facProgram(self):
        '''
        program de la 10 la 22
        '''
        program = []
        timp = 0
        emisiuni = self.getEmisiuni()
        while timp <= 12:
            gasit = 0
            numar = random.randint(0,self.cateEmisiuni()-1)
            emisiune = emisiuni[numar]
            if emisiune.getTip() in self.programeBlocate:
                    gasit = 1
            if gasit == 0:
                program.append(emisiuni[numar])
                timp += int(emisiuni[numar].getDurata())
        
        return program
        
    def blochezProgram(self,tip):
        '''
        :param tip: stringul de programe blocate
        '''
        self.programeBlocate = tip
    
    
    
    
    
