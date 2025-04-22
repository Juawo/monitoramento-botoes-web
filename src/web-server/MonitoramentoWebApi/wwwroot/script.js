async function atualizarDados() {
    try {
        const response = await fetch('/dados');
        const json = await response.json();

        console.log(json);
        
        document.getElementById('temp').textContent = json.temperature.toFixed(2);
        document.getElementById('btnA').textContent = json.btn_a_state == 1 ? "Pressionado" : "Solto";
        document.getElementById('btnB').textContent = json.btn_b_state == 1 ? "Pressionado" : "Solto";
    } catch (e) {
        console.error("Erro ao buscar dados : ", e);
    }
}

setInterval(atualizarDados, 1000);
atualizarDados();