# Documentação do Código do AGV Seguidor de Linha
Este código é usado para controlar um AGV (Veículo Guiado Automático) que segue uma linha usando três sensores de obstáculos e uma ponte H L298N para controlar os motores.


## Definições de Pinos
Os pinos dos motores e sensores são definidos no início do código:
Atv_A:
Este jumper é responsável por desativar ou ativar o motor A para ser controlado pelo Arduino ou outra placa.

Este jumper funciona da seguinte forma: um dos terminais possui 5V (ou a tensão de alimentação VLogic), e o outro terminal é o que vai para o chip L298N.  A placa possui um resistor de pull-down no outro resistor, o que significa que quando o jumper é solto, o terminal ficará com nível lógico baixo, e o chip entenderá que é necessário desabilitar o motor A. Mas quando o jumper é colocado entre os terminais, o 5V é ligado ao terminal de sinal pelo jumper. Com isso, o sinal de nível alto é enviado ao chip L298n e ele entende que os motores devem estar habilitados para os acionamentos.

pin_S1, pin_S2 e pin_S3 são os pinos dos sensores de obstáculos. pin_S3 é o sensor do meio usado para seguir a linha.

## Configuração Inicial
Na função setup(), os pinos dos motores são configurados como saída e a direção inicial dos motores é definida para frente. Os pinos dos sensores são configurados como entrada.

## Loop Principal
Na função loop(), o valor lido de cada sensor é armazenado nas variáveis Sensor1, Sensor2 e Sensor3.

A lógica de controle do robô é baseada nos valores lidos dos sensores:

Se o sensor do meio (Sensor3) detectar a linha (valor 1), ambos os motores são ligados na mesma velocidade, fazendo o robô seguir em frente.

Se o sensor da esquerda (Sensor1) detectar a linha e o sensor do meio não, o motor da esquerda é desligado e o motor da direita é ligado, fazendo o robô virar para a esquerda.
Se o sensor da direita (Sensor2) detectar a linha e o sensor do meio não, o motor da direita é desligado e o motor da esquerda é ligado, fazendo o robô virar para a direita.
Essa lógica permite que o robô siga a linha e faça ajustes de direção conforme necessário.



