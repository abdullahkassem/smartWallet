const portNum = 8081;

function addToQueryString(baseUrl, params) {
    if (!params.length) return baseUrl; // No params, return base URL
  
    const queryString = params.map(param => `${encodeURIComponent(param[0])}=${encodeURIComponent(param[1])}`)
      .join('&');
  
    return `${baseUrl}${queryString}`;
  }


export function normalFetch(funcType,dict=[]) {

    // [["name","abdullah"],["password","myPass"]]
    const tempURL = ' http://localhost:'+portNum+'/?funcType='+funcType+'&'
    let newURL = addToQueryString(tempURL,dict);
    console.log("new url is ",newURL);

    return fetch(newURL,{
        mode: 'cors'
        })
        // .then(response => response.text())
        // .then(data => {
        // console.log(data); // The response body as text
        // })
        // .catch(error => {
        // console.error(error);
        // }); 

}
  

export function loginAPI(userName,Pass){
  return normalFetch("login",[["userName",userName],["password",Pass]])
}