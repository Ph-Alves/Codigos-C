import threading
import time

# Definição peças
# 0 - vazio
# 1 - peça branca (b)
# 2 - peça preta (p)
# 3 - dama branca (B)
# 4 - dama preta (P)

def inicializarTabuleiro():
    tabuleiro = [[0] * 8 for _ in range(8)]
    
    for i in range(3):
        for j in range((i % 2), 8, 2):
            tabuleiro[i][j] = 1
    
    for i in range(5, 8):
        for j in range((i % 2), 8, 2):
            tabuleiro[i][j] = 2
    
    return tabuleiro

def imprimirTabuleiro(tabuleiro):
    print("  ", end="")
    for i in range(8):
        print(f" {i} ", end="")
    print()
    for i in range(8):
        print(f"{i} ", end="")
        for j in range(8):
            if tabuleiro[i][j] == 0:
                print(" - ", end="")
            elif tabuleiro[i][j] == 1:
                print(" b ", end="")
            elif tabuleiro[i][j] == 2:
                print(" p ", end="")
            elif tabuleiro[i][j] == 3:
                print(" B ", end="")
            elif tabuleiro[i][j] == 4:
                print(" P ", end="")
        print("")
    print("")

def movimentoValido(tabuleiro, linha, coluna, novaLinha, novaColuna, jogador):
    if novaLinha < 0 or novaLinha >= 8 or novaColuna < 0 or novaColuna >= 8:
        return False
    if tabuleiro[novaLinha][novaColuna] != 0:
        return False
    
    deltaLinha = novaLinha - linha
    deltaColuna = novaColuna - coluna

    peca = tabuleiro[linha][coluna]

    if abs(deltaLinha) == abs(deltaColuna):
        if peca in [1, 2]:  # Peças normais
            if abs(deltaLinha) == 1:
                if jogador == 1 and deltaLinha == 1:
                    return True
                if jogador == 2 and deltaLinha == -1:
                    return True
            elif abs(deltaLinha) == 2:
                meioLinha = (linha + novaLinha) // 2
                meioColuna = (coluna + novaColuna) // 2
                if tabuleiro[meioLinha][meioColuna] != 0 and tabuleiro[meioLinha][meioColuna] not in [jogador, jogador + 2]:
                    if jogador == 1 and deltaLinha == 2:
                        return True
                    if jogador == 2 and deltaLinha == -2:
                        return True
        elif peca in [3, 4]:  # Damas
            deltaLinhaSign = 1 if deltaLinha > 0 else -1
            deltaColunaSign = 1 if deltaColuna > 0 else -1
            meioLinha = linha + deltaLinhaSign
            meioColuna = coluna + deltaColunaSign
            while meioLinha != novaLinha and meioColuna != novaColuna:
                if tabuleiro[meioLinha][meioColuna] != 0:
                    if meioLinha == novaLinha - deltaLinhaSign and meioColuna == novaColuna - deltaColunaSign:
                        if tabuleiro[meioLinha][meioColuna] not in [jogador, jogador + 2]:
                            return True
                    return False
                meioLinha += deltaLinhaSign
                meioColuna += deltaColunaSign
            return True
    return False

def moverPeca(tabuleiro, linha, coluna, novaLinha, novaColuna, jogador):
    if movimentoValido(tabuleiro, linha, coluna, novaLinha, novaColuna, jogador):
        deltaLinha = novaLinha - linha
        deltaColuna = novaColuna - coluna

        if abs(deltaLinha) == 2:
            meioLinha = (linha + novaLinha) // 2
            meioColuna = (coluna + novaColuna) // 2
            tabuleiro[meioLinha][meioColuna] = 0
        elif abs(deltaLinha) > 2:  # Movimento de dama
            deltaLinhaSign = 1 if deltaLinha > 0 else -1
            deltaColunaSign = 1 if deltaColuna > 0 else -1
            meioLinha = linha + deltaLinhaSign
            meioColuna = coluna + deltaColunaSign
            while meioLinha != novaLinha and meioColuna != novaColuna:
                if tabuleiro[meioLinha][meioColuna] not in [0, jogador, jogador + 2]:
                    tabuleiro[meioLinha][meioColuna] = 0
                    break
                meioLinha += deltaLinhaSign
                meioColuna += deltaColunaSign
        
        tabuleiro[novaLinha][novaColuna] = tabuleiro[linha][coluna]
        tabuleiro[linha][coluna] = 0

        # Peça para dama
        if jogador == 1 and novaLinha == 7:
            tabuleiro[novaLinha][novaColuna] = 3
        elif jogador == 2 and novaLinha == 0:
            tabuleiro[novaLinha][novaColuna] = 4

        return True
    else:
        print("Movimento inválido")
        time.sleep(1);
        return False

def checarVitoria(tabuleiro):
    pecaBranca = sum(row.count(1) + row.count(3) for row in tabuleiro)
    pecaPreta = sum(row.count(2) + row.count(4) for row in tabuleiro)
    
    if pecaBranca == 0:
        print("Jogador 2 venceu")
        return True
    elif pecaPreta == 0:
        print("Jogador 1 venceu")
        return True
    
    return False

def obterEntrada(mensagem):
    while True:
        try:
            valor = int(input(mensagem))
            if 0 <= valor < 8:
                return valor
            else:
                print("Entrada inválida\nDigite um número entre 0 e 7.")
                time.sleep(1)
        except ValueError:
            print("Entrada inválida\nDigite um número inteiro.")
            time.sleep(1)

class JogoDamas:
    def __init__(self):
        self.tabuleiro = inicializarTabuleiro()
        self.turno = 1
        self.lock = threading.Lock()
        self.cond = threading.Condition(self.lock)
        self.vitoria = False

    def jogador(self, jogador):
        while not self.vitoria:
            with self.cond:
                while self.turno != jogador:
                    self.cond.wait()
                if self.vitoria:
                    break
                imprimirTabuleiro(self.tabuleiro)
                print(f"Jogador {jogador}, é a sua vez.")
                linha = obterEntrada(f"Jogador {jogador}, digite a linha da peça que deseja mover: ")
                coluna = obterEntrada(f"Jogador {jogador}, digite a coluna da peça que deseja mover: ")
                novaLinha = obterEntrada(f"Jogador {jogador}, digite a nova linha: ")
                novaColuna = obterEntrada(f"Jogador {jogador}, digite a nova coluna: ")
                
                if moverPeca(self.tabuleiro, linha, coluna, novaLinha, novaColuna, jogador):
                    self.vitoria = checarVitoria(self.tabuleiro)
                    self.turno = 3 - jogador  # Alterna entre 1 e 2
                self.cond.notify_all()

def main():
    jogo = JogoDamas()
    
    jogador1 = threading.Thread(target=jogo.jogador, args=(1,))
    jogador2 = threading.Thread(target=jogo.jogador, args=(2,))
    
    jogador1.start()
    jogador2.start()
    
    jogador1.join()
    jogador2.join()

if __name__ == "__main__":
    print("Bem-vindo ao jogo de damas!\nJogador 1 são as brancas(b) e jogador 2 são as pretas(p)")
    main()
