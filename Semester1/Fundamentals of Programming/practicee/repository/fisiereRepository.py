from domain.entitati import Student
class RepositoryFisiere():
    
    def __init__(self, numeFisier):
        self.numeFisier = numeFisier
    
    def iauStudentLinie(self, linie):
        
        delimitator = linie.split(",")
        st = Student(delimitator[0],delimitator[1],delimitator[2])
        return st
    
    def loadFromFile(self):
        
        try:
            fisier = open(self.numeFisier)
        except IOError:
            print("fisieru nu exista")
            return
        
        studenti = []
        linie = fisier.readline.strip()
        
        while linie != "":
            delimitator = linie.split(",")
            student = Student(delimitator[0],delimitator[1],delimitator[2],delimitator[3])
            studenti.append(student)
            linie = fisier.readline.strip()
        
        return studenti
        
    


