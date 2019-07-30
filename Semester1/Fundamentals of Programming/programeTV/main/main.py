'''
Created on 14 feb. 2019
Main
Voi folosi arhitectura stratificata:
UI -> SERVICE -> REPOSITORY
@author: Edy
'''
from domain.validator import ValidatorEmisiune
from Ui.consola import Consola
from control.service import Service
from repository.repository import RepositoryEmisiune

repository = RepositoryEmisiune("emisiuni.txt")
validator = ValidatorEmisiune()
service = Service(validator, repository)
consola = Consola(service)

consola.showUi()