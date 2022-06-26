from keras.datasets import fashion_mnist
import numpy as np
import matplotlib.pyplot as plt
import mahotas
import mahotas.demos
from sklearn.metrics import confusion_matrix
from string import ascii_uppercase
import pandas as pd
import seaborn as sns

(x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()

y_train = y_train[0:100]
x_train = x_train[0:100]

#-----------TEST----------

trouserTest = np.where(y_test == 1)[0]
trouserTest = trouserTest[0:100]

dressTest = np.where(y_test == 3)[0] 
dressTest = dressTest[0:100]

shirtTest = np.where(y_test == 6)[0]
shirtTest = shirtTest[0:100]

snaekerTest = np.where(y_test == 7)[0]
snaekerTest = snaekerTest[0:100]

#-----------TRAIN----------

trouserTrain = np.where(y_train == 1)[0]
trouserTrain = trouserTrain[0:1000]

dressTrain = np.where(y_train == 3)[0] 
dressTrain = dressTrain[0:1000]

shirtTrain = np.where(y_train == 6)[0]
shirtTrain = shirtTrain[0:1000]

snaekerTrain = np.where(y_train == 7)[0]
snaekerTrain = snaekerTrain[0:1000]

listaTest = [trouserTest, dressTest, shirtTest, snaekerTest]
y_trainCategorias = np.concatenate((trouserTrain, dressTrain, shirtTrain, snaekerTrain), axis=None)

x_train_2=[]
y_train_2=[]
for i in range(len(y_trainCategorias)):
  y = y_trainCategorias[i]
  x_train_2.append(x_train[y,:])
  y_train_2.append(y_train[y])

resultadoListTotal = []
listaResultado = []
resultado = 10

for i in range(len(listaTest)):
  resultados = []
  listaposicionTrain = []
  for j in range(100):
    posicionesTest = listaTest[i][j]
    for k in range(len(x_train_2)):
      imageTest = x_test[posicionesTest,:]
      imageTrain = x_train_2[k]
      momentoTest = mahotas.features.zernike_moments(imageTest, 10)
      momentoTrain = mahotas.features.zernike_moments(imageTrain, 10)

      distancia = np.linalg.norm(momentoTest - momentoTrain)
      if(distancia < resultado):
        resultado = distancia
        posicionTrain = k

    resultados.append(resultado)
    listaposicionTrain.append(posicionTrain)
    resultado = 10

  resultadoListTotal.append(resultados)
  listaResultado.append(listaposicionTrain)

resultadosFinalesTest = []
resultadosFinalesTrain = []

for i in range(4):
  for j in range(100):
    posicion=listaResultado[i][j]
    posicion2=listaTest[i][j]
    valorTrain = y_train_2[posicion]
    valorTest = y_test[posicion2]
    resultadosFinalesTrain.append(valorTrain)
    resultadosFinalesTest.append(valorTest)

matriz = confusion_matrix(resultadosFinalesTrain, resultadosFinalesTest)
print("Matriz de Confusión")
print(matriz)

categorias = ['trouser','dress','shirt','snaeker']
mapaCalor = pd.DataFrame(matriz, index= categorias, columns= categorias)
diagrama = sns.heatmap(mapaCalor, cmap= 'flare', annot= True)
plt.show()