(ns notas.core
  (:require [clojure.string :as str]))

(defn parse-int [s]
  (try
    (Integer/parseInt (str/trim s))
    (catch Exception _ nil)))

(defn parse-double-br
  "Aceita números com ponto OU vírgula (ex.: 92.5 ou 92,5)."
  [s]
  (try
    (Double/parseDouble (-> s (or "") str/trim (str/replace #"," ".")))
    (catch Exception _ nil)))

(defn ler-int! [prompt]
  (loop []
    (print prompt) (flush)
    (if-some [s (read-line)]
      (if-some [v (parse-int s)]
        v
        (do (println "Valor inválido. Digite um número inteiro.") (recur)))
      (do (println "Entrada vazia. Tente novamente.") (recur)))))

(defn ler-nota! []
  (loop []
    (print "Nota (0–100): ") (flush)
    (if-some [s (read-line)]
      (if-some [v (parse-double-br s)]
        (if (and (<= 0 v) (<= v 100))
          v
          (do (println "A nota deve estar entre 0 e 100.") (recur)))
        (do (println "Valor inválido. Ex.: 75, 92.5 ou 92,5.") (recur)))
      (do (println "Entrada vazia. Tente novamente.") (recur)))))

(defn conceito [nota]
  (cond
    (>= nota 90) "A"
    (>= nota 80) "B"
    (>= nota 70) "C"
    (>= nota 60) "D"
    :else        "F"))

(defn -main [& _]
  (let [qtd (max 1 (ler-int! "Quantos alunos na turma? "))]
    (println)
    (loop [i 1, soma 0.0, aprov 0]
      (if (> i qtd)
        (let [media (/ soma qtd)
              desempenho (if (>= media 80) "Turma excelente!"
                             (if (>= media 60) "Bom desempenho!"
                               "É necessário melhorar!"))]
          (println (format "\nMédia da turma: %.1f" media))
          (println (str   "Aprovados: " aprov))
          (println (str   "Desempenho geral: " desempenho)))
        (do
          (print (format "Nome do aluno %d: " i)) (flush)
          (let [raw (read-line)
                nome (let [n (some-> raw str/trim)]
                       (if (str/blank? n) (str "Aluno-" i) n))
                nota (ler-nota!)
                conc (conceito nota)
                aprov? (>= nota 60)]
            (println (format "%s - Conceito: %s" nome conc))
            (println)
            (recur (inc i)
                   (+ soma nota)
                   (if aprov? (inc aprov) aprov))))))))
