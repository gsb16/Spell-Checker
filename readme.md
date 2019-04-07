# Verificador Ortográfico de arquivo txt em português

## Gabriel Barreto - GRR20166812

## Objetivos:
Projeto da disciplina ci067 de 2016/2
- Implementação de verificador ortográfico que marca palavras erradas;
- Manipulação de arquivos e uso de Makefile;

## Compilação:
- *make:* compilação do código e criação do executável "ortografia"
- *make clean:* remove arquivos temporários
- *make purge:* executa o make clean e deleta o executável

## Execução:
- O dicionário usado no código é de português brasileiro.
- No caso da saída "Dicionario nao encontrado", instalar com o comando:
```
sudo apt-get install wbrazilian
``` 
- Comando para execução do verificador ortográfico:
```
./ortografia < entrada.txt > saida.txt
``` 
 
### Obs.: Para alteração do idioma, basta alterar o caminho do dicionário na função ledicionario()
