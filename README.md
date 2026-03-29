# stm32-debounce

Rotina de debounce de botão com soft timer em STM32F4xx — registradores diretos (sem HAL).

## Descrição

Implementação de debounce por software usando polling de timer de hardware (TIM10). O botão PC13 controla o pisca-pisca do LED PA5, com leitura dupla do estado do botão para eliminar ruído mecânico.

## Hardware

- Microcontrolador: STM32F4xx (Nucleo-F401RE / F411RE)
- LED: PA5
- Botão: PC13 (ativo em LOW)

## Configuração do Timer

| Parâmetro | Valor |
|-----------|-------|
| Timer | TIM10 |
| PSC | 1599 → 10 kHz |
| ARR | 49 → estouro a cada 5 ms |
| Tempo de pisca | 25 × 5 ms = 125 ms |

## Técnica de debounce

Amostragem dupla do botão a cada ciclo de 5 ms:
```c
botao[1] = botao[0];
botao[0] = (ButtonPort->IDR & Button) == BUTTONPRESSED;
if (botao[0] == botao[1]) { /* estado estável */ }
```

## IDE

Atollic TrueSTUDIO 9.3

## Autores

Prof. Marcos Zuccolotto & Turma 4324 — Centro Tecnológico Liberato
