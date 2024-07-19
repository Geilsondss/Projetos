#CADASTRO IMOBILIÁRIO
#Este código realiza o cadastro imobiliário do usuario.
#A entrada é composta por diversas informações sobre o usuario e o que ele busca em sua futura moradia.
#Seu trabalho é encontrar estas informações é aloca-las em seus respectivos lugares.

entrada = input()

#modalidade(ok)
aluguel = entrada.lower().count('alug')
if aluguel > 0:
    print('Modalidade: Aluguel')
 
venda = entrada.lower().count('vend')
if venda > 0:
    print('Modalidade: Venda')

#tipo(ok)
apartamento = entrada.lower().count('apartamento')
if apartamento > 0:
    print('Tipo: Apartamento')

casa = entrada.lower().count('casa')
if casa > 0:
    print('Tipo: Casa')


#endereço(ok)
modificação = entrada.split()
endereço = ""
parada = 0
busca = 0
for i in modificação:    
    if i == "Rua" or i == "Avenida":
        busca = modificação.index(i)

while True:
    if parada >= 1 :
            break
    if  not modificação[busca].rstrip(',').rstrip('.').isdigit():
        endereço += modificação[busca] + " "
        busca += 1
    else:
        modificação[busca] = modificação[busca].replace(",","").replace(".","")
        endereço += modificação[busca]
        parada += 1 
print(f'Endereco: {endereço}')


#cep(ok)
cep_esquerda = entrada.find('-')
procura_es_final = cep_esquerda -5
procura_es = cep_esquerda +4
digitos_esquerda = entrada[procura_es_final:cep_esquerda]
cep_direita = entrada.rfind('-')
procura_dr = cep_direita +4
procura_dr_final = cep_direita - 5
digitos_direita =entrada[procura_dr_final:cep_direita]

verificaçao_e = digitos_esquerda.isdigit()
verificaçao_d = digitos_direita.isdigit()
if verificaçao_d == True or verificaçao_e == True:
    if entrada[procura_es] == ',' or entrada[procura_es] == '.' or entrada[procura_es] == ' ':
        traço_cep1 = entrada.find('-')
        começo1 = traço_cep1 -5
        final1 = traço_cep1 + 4
        if entrada[final1] == '.' or entrada[final1] == ',' or entrada[final1] == ' ':
            print(f'CEP: {entrada[começo1:traço_cep1]+entrada[traço_cep1:traço_cep1+4]}')
        else:
            traço_cep2 = entrada.rfind('-')
            começo2 = traço_cep2 -5
            final2 = traço_cep2 + 4
            if entrada[final2] == '.' or entrada[final2] == ',' or entrada[final2] == ' ':
                print(f'CEP: {entrada[começo2:traço_cep2]+entrada[traço_cep2:traço_cep2+4]}')

    elif entrada[procura_dr] == ',' or entrada[procura_dr] == '.' or entrada[procura_dr] == ' ':
        traço_cep3 = entrada.find('-')
        começo3 = traço_cep3 -5
        final3 = traço_cep3 + 4
        if entrada[final3] == '.' or entrada[final3] == ',' or entrada[final3] == ' ':
            print(f'CEP: {entrada[começo3:traço_cep3]+entrada[traço_cep3:traço_cep3+4]}')
        else:
            traço_cep4 = entrada.rfind('-')
            começo4 = traço_cep4 -5
            final4 = traço_cep4 + 4
            if entrada[final4] == '.' or entrada[final4] == ',' or entrada[final4] == ' ':
                print(f'CEP: {entrada[começo4:traço_cep4]+entrada[traço_cep4:traço_cep4+4]}')
    else:
        print('CEP: nao informado')
else:
    print('CEP: nao informado')

        
#area(ok)
metros_posição = entrada.lower().find('metros quadrados')
m2_posição = entrada.lower().find('m2')
valor_metros = metros_posição - 2
valor_m2 = m2_posição -2
total_metros = ''
total_m2 = ''
ordem_metros = ''
ordem_m2 = ''
organizar =  -1
area_metros = entrada.lower().count('metros quadrados')
area_m2 = entrada.lower().count('m2')
if area_metros == 0 and  area_m2 == 0:
    print('Area: nao informado')
elif area_metros > 0:
    if valor_metros > 0:
        while entrada[valor_metros] != ' ':
            total_metros += entrada[valor_metros]
            valor_metros = valor_metros - 1
        for i in range(len(total_metros)):
            ordem_metros += total_metros[organizar]
            organizar = organizar -1
            
    print(f'Area: {ordem_metros}')
else:
    if valor_m2 > 0:
        while entrada[valor_m2] != ' ':
            total_m2 += entrada[valor_m2]
            valor_m2 = valor_m2 - 1
        for i in range(len(total_m2)):
            ordem_m2 += total_m2[organizar]
            organizar = organizar -1
        print(f'Area: {ordem_m2}')

#valor(ok)
posição_rs = entrada.lower().find('r$')
posição_reais = entrada.lower().find('reais')
valor_Rss = posição_rs +2
valor_Reais = posição_reais -2
total_rs = ''
total_reais = ''
ordem_rs = ''
ordem_reais = ''
organizar_valor =  -1
valor_rs = entrada.lower().count('r$')
valor_reais = entrada.lower().count('reais')
if valor_rs == 0 and  valor_reais == 0:
    print('Valor: nao informado')
    
elif valor_rs > 0:
    if valor_Rss > 0:
        while entrada[valor_Rss] != ' ':
            total_rs += entrada[valor_Rss]
            valor_Rss = valor_Rss +1
        if total_rs[-1] == ',' or total_rs[-1] == '.':
            print(f'Valor: {total_rs[:-1]}')
        else:
            print(f'Valor: {total_rs}')
        
else:
    if valor_Reais > 0:
        while entrada[valor_Reais] != ' ':
            total_reais += entrada[valor_Reais]
            valor_Reais = valor_Reais - 1
        for i in range(len(total_reais)):
            ordem_reais += total_reais[organizar_valor]
            organizar_valor = organizar_valor -1
        if ordem_reais[-1] == ',' or ordem_reais[-1] == '.':
            print(f'Valor: {ordem_reais[:-1]}')
        else:
            print(f'Valor: {ordem_reais}')


#telefone(ok)
telefone = ''
digitos = '0987654321'
for c in range(len(entrada)):
    if entrada[c] == '-':
        if c+4 < len(entrada):
            if entrada[c+4] in digitos:
                if entrada[c-5] in digitos:
                    telefone += ', '
                    telefone += (entrada[c-5:c+5])
                else:
                    telefone += ', '
                    telefone += (entrada[c-4:c+5])
if telefone != '':
    if len(telefone) == 11:
        print(f'Telefone: {telefone[-9:]}')
    elif len(telefone) == 12:
        print(f'Telefone: {telefone[-10:]}')
    else:
        print(f'Telefones: {telefone[-21:]}')


#respondavel( ok)
modificador = entrada.split()
responsavel = ''
count_maiusculas = 0

for i in reversed(modificador):
    if i[0].isupper():
        responsavel = i.replace(",","").replace(".","") + ' ' + responsavel
    elif not i[0].isupper() and responsavel:
        break
print(f'Responsavel: {responsavel}')
