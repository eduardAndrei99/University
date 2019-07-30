
class RepositoryExceptie(Exception):
    pass


class inMemorieRepository():
    
    def __init__(self):
        self.studenti = []
    
    def adaugStudent(self,student):
        
        for st in self.studenti:
            if st.getId() == student.getId():
                raise RepositoryExceptie
        self.studenti.append(student)
        
    def getAllStudent(self):
        return self.studenti
    

    


