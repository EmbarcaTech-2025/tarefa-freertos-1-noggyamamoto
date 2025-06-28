
# Tarefa: Roteiro de FreeRTOS #1 - EmbarcaTech 2025

Autor: **João Nogueira**

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Brasília, 28 de 2025

---

## 📝 Reflexão

**O que acontece se todas as tarefas tiverem a mesma prioridade?**  
Se todas as tarefas tiverem a mesma prioridade, o escalonador do FreeRTOS irá alternar entre elas de forma justa, usando o método round-robin. Cada tarefa executa até ser bloqueada (por exemplo, ao chamar `vTaskDelay`) ou até o fim do seu tempo de fatia, garantindo que todas recebam tempo de CPU de maneira equilibrada.

**Qual tarefa consome mais tempo da CPU?**  
A tarefa que consome mais tempo de CPU é aquela que executa mais frequentemente ou permanece mais tempo em estado de execução. No código deste projeto, a tarefa dos botões (`tarefa_botoes`) roda em um loop com um atraso muito pequeno (10 ms), realizando polling constante, o que faz com que ela consuma mais tempo de CPU em comparação com as tarefas de LED e buzzer, que possuem delays maiores.

**Quais seriam os riscos de usar polling sem prioridades?**  
O uso de polling sem prioridades pode causar desperdício de processamento, pois tarefas ficam constantemente verificando o estado de entradas, mesmo quando não há mudanças. Isso pode levar a um consumo excessivo de CPU, dificultando a execução de outras tarefas importantes, além de aumentar o consumo de energia. Sem prioridades, tarefas críticas podem não receber o tempo de CPU necessário, prejudicando a resposta do sistema a eventos importantes.

---

## 📜 Licença
GNU GPL-3.0.
