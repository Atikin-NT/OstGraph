import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

def main(file_path: str):
    with open(file_path, 'r') as file:
        data = file.readlines()

    all_data = []
    x_data = []
    i = 1
    STEP = 1
    for line in data:
        kr, pr = line.split(' ')

        all_data.append(float(kr.strip()))
        all_data.append(float(pr.strip()))
        x_data.append(i)
        x_data.append(i)
        i += STEP


    a = pd.DataFrame({
        'x': x_data,
        'val': all_data,
        'Algorithm': ['Kruskal' if i % 2 == 0 else 'Prima' for i in range(0, len(x_data), 1)]
    })


    line,ax = plt.subplots(figsize=(10,6))

    ax = sns.lineplot(data=a, palette="magma", x='x', y='val', hue='Algorithm', style='Algorithm')
    ax.set_xlabel('Кол-во вершин в графе')
    ax.set_ylabel('Время работы в сек')
    ax.set_title('Количество ребер = 1000 * n')

    line.savefig("./data/test_step1_m_2.png")

    plt.show()


if __name__ == '__main__':
    main('./data/test_step1_m_2.txt')
