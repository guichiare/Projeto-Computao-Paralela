Projeto Computação Paralela Pt.1
Desenvolvimento Inicial e Metas para Entrega Final

  Para comparação inicial, foram usados 65 casas decimais. Três códigos diferentes foram usados para esta entrega,
um código serial e dois códigos com métodos diferentes de paralelização. Todos os teste foram feitos com 10000 iterações.

O código Serial por algum motivo retornou apenas 18 casas decimais de euler corretamente,
sendo que eram esperadas bem mais considerando o número de iterações, 
uma das metas principais do projeto para a entrega final será descobrir a origem do erro.
Até que o erro seja corrigido, o valor alcançado pelo código serial será usado para comparação com os códigos paralelos.

Tempo de processamento serial(e(10000)): 4,674 segundos

O primeiro código paralelo divide o somatório pelo número de processadores em partes iguais e os resultados são somados no resultado global.
Apesar de apresentar o mesmo resultado do código serial,
infelizmente esse método não devolveu uma diminuição significativa no tempo de processamento.
![image](https://github.com/guichiare/Projeto-Computao-Paralela/assets/64621991/97e6d42e-d029-43d1-9200-075ccc78a35a)
Tempo de processamento(e(10000)): 3,935 segundos **SpeedUp = 1,18**

O segundo código paralelo divide o somátorio intercalando as iterações entre os processadores,
cada processo usa o seu índice para primeira iteração e soma o número de processos ao seu índice para a próxima iteração.
Esse método conseguiu diminuir o tempo de processamento pela metade,
mas, apesar de alcançar 18 casas decimais de precisão assim como o código serial, as casas seguintes diferem entre eles.
![image](https://github.com/guichiare/Projeto-Computao-Paralela/assets/64621991/65c1838d-c88b-467e-9947-43012ede6128)
Tempo de processamento(e(10000)): 2,325 segundos **SpeedUp = 2,01**

Os objetivos do projeto para a entrega final são corrigir as casas decimais incorretas no processo serial,
descobrir por que o resultado do segundo código paralelo difere com o resultado do código serial e
integrar variáveis que possam alcançar mais casas decimais.

Resultados dos testes

![image](https://github.com/guichiare/Projeto-Computao-Paralela/assets/64621991/1d26ebb0-57c2-4654-b535-5abf60af01a1)







Projeto Computação Paralela Pt.2
Correção de erros e Finalização do Projeto

  A primeira e mais clara suspeita da falta de precisão do valor alcançado em euler foi o nível de precisão da variável "long double", sendo assim, uma segunda versão do código serial foi implementada utilizando variáveis da biblioteca "gmp", que foram criadas especificamente para alcançar níveis de precisão extraordinários. Alem disso, ao invés de realizar o fatorial de n a cada iteração do cálculo, fat é inicializado como 1 e é multiplicado pelo índice da iteração para reduzir o número de cálculos que os processadores precisam realizar. A segunda versão serial (eulerS2.c) não apenas ultrapassou as 65 casas de teste da comparação inicial como também trouxe uma significante diminuição no tempo de processamento do código, superando as duas primeiras versões paralelas.
  
<img width="738" alt="image" src="https://github.com/guichiare/Projeto-Computao-Paralela/assets/64621991/6494914e-8640-4c9a-9749-68cf681e990f">

  Com a finalidade de alcançar um valor maior de casas decimais de euler, foi necessário alocar mais bits de memória as variáveis usadas no cálculo principal em troca de tempo de processamento. Alocando 2097152 bits de memória à euler, foi possível alcançar um máximo de **236838 casas de euler atravez de 55000 iterações.** É possível ultrapassar este valor aumentando ainda mais ambos os valores de bits alocados a cada variável e o número de iterações.

A valor alcançado pode ser visto em eulerresult.txt e este valor pode ser testado executando eulerCompare.c

![image](https://github.com/guichiare/Projeto-Computao-Paralela/assets/64621991/d4dafbc9-71f4-4642-a8fd-678af42b304f)

Tempo de processamento serial(e(55000)): 13m18s

Tempo de processamento paralelo(e(55000)): 7m58s **SpeedUp = 1,66**
