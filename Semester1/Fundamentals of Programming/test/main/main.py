'''
Created on 10 dec. 2018

Main ul

Arhitectura stratificata

Ui -> service -> repository

@author: Edy
'''

from ui.consola import consola
from service.service import serviceTelefon
from repository.repository import repositoryTelefon

repository = repositoryTelefon("telefoane.txt")
service = serviceTelefon(repository)
consola = consola(service)

consola.showUi()








