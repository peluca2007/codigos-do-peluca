<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        body{
            font:normal 20px Arial, Helvetica, sans-serif;
            background-color: #8f09096c;
            color: #ffffff;
            text-align: center;
            padding: 20px;
        }
        h1{
            color: #fff;
        }
        h2{
            color: #fff;
        }


    </style>
</head>
<body>
    <h1>Calculadora de Média</h1>
    <script>
var qnome = window.prompt(`Quantos alunos tem na sala?`);
for(let i = 0; i < qnome; i++){



var nome = window.prompt(`Qual o nome do(a) aluno(a) ?`);
var n1 = Number(window.prompt(`Qual a primeira nota do(a) ${nome}?`));
var n2 = Number(window.prompt(`Qual a segunda nota do(a) ${nome}?`));

var s= (n1 + n2);
var m= s / 2;
window.alert(`A soma das notas do(a) ${nome} é ${s}`);
window.alert(`A média do(a) ${nome} é ${m}`);

if(m >= 6){
    document.writeln(`O(a) aluno(a) ${nome} está aprovado(a) com média ${m}<br>`);
}
else{
    document.writeln(`O(a) aluno(a) ${nome} está reprovado(a) com média ${m}<br>`);
}
} 
    </script> 


</body>
</html>
