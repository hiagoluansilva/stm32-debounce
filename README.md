# STM32 Debounce — Eliminação de Ruído em Botão

🇧🇷 **Português** | 🇺🇸 [English](#english)

---

## Português

Implementação de debounce de botão por software no STM32F4324 usando TIM10 para gerar tick de 5 ms e dupla amostragem.

### O que faz
- Usa **TIM10** para gerar interrupção a cada **5 ms**
- Aplica técnica de **dupla amostragem** para eliminar bouncing
- Ao detectar botão estável: alterna LED a cada **125 ms**

### Configuração do Timer
```
TIM10: PSC = 1599, ARR = 49
Período = 84 MHz / (1600 × 50) = 5 ms por tick
```

### Algoritmo
1. A cada 5 ms lê o estado do botão
2. Compara com leitura anterior
3. Somente confirma transição se dois estados consecutivos coincidirem
4. Toggle no LED a cada 125 ms quando botão pressionado

### Microcontrolador
STM32F4324 — Atollic TrueSTUDIO

---

## English

Software button debounce on STM32F4324 using TIM10 for a 5 ms tick and double-sampling technique.

### What it does
- Uses **TIM10** to generate an interrupt every **5 ms**
- Applies **double-sampling** to eliminate contact bouncing
- On confirmed button press: toggles LED every **125 ms**

### Timer configuration
```
TIM10: PSC = 1599, ARR = 49
Period = 84 MHz / (1600 × 50) = 5 ms per tick
```

### Algorithm
1. Every 5 ms, read button state
2. Compare with previous reading
3. Confirm transition only if two consecutive readings match
4. Toggle LED every 125 ms when button is held

### MCU
STM32F4324 — Atollic TrueSTUDIO
