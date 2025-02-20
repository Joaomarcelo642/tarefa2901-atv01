# Tarefa Clock e Temporizadores - Atividade 01: Temporizador periódico.

Este projeto implementa a alternância sequencial de três LEDs utilizando a placa Raspberry Pi Pico e um temporizador para gerenciar o tempo de ativação de cada LED.

## Descrição

O código configura três LEDs conectados aos pinos GPIO da Raspberry Pi Pico e utiliza um temporizador para alternar entre eles a cada 3 segundos. Durante a execução:

- Apenas um LED fica aceso por vez.
- A cada 3 segundos, o LED ativo é desligado e o próximo na sequência é aceso.
- A alternância segue a ordem: LED1 (Azul) → LED2 (Vermelho) → LED3 (Verde) → LED1...

Mensagens são impressas no console para indicar qual LED está aceso.

## Hardware Utilizado

- Raspberry Pi Pico
- 3 LEDs (Azul, Vermelho, Verde)
- 3 resistores de 220Ω (um para cada LED)
- Jumpers e protoboard

## Pinos Utilizados

- **LED1 (Azul)**: GPIO 12
- **LED2 (Vermelho)**: GPIO 13
- **LED3 (Verde)**: GPIO 11

## Bibliotecas Necessárias

- pico/stdlib.h
- hardware/timer.h
- stdio.h

## Funcionamento

1. Inicializa os pinos dos LEDs como saída.
2. Configura um temporizador para executar a cada 3 segundos.
3. O temporizador chama uma função de callback que:
   - Desliga todos os LEDs.
   - Acende o próximo LED na sequência.
   - Exibe uma mensagem no console informando qual LED está ligado.
4. O processo se repete indefinidamente.

## Compilação

Utilize o SDK do Raspberry Pi Pico com CMake para compilar o código.


## Autor

João Marcelo Nascimento Fernandes - Desenvolvido como parte de estudos de sistemas embarcados.

