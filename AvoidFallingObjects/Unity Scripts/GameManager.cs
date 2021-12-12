using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI; 

public class GameManager : MonoBehaviour
{
    private static GameManager _instance; //singletone : easier access
    public static GameManager Instance
    {
        get
        {
            if(_instance == null)
            {
                _instance = FindObjectOfType<GameManager>();
            }
            return _instance;
        }
    }// till here

    [SerializeField]
    private GameObject poop;
    //Use this for Initialization

    private int score;

    [SerializeField]
    private Text scoreTxt;

    [SerializeField] 
    private Transform objbox;

    [SerializeField]
    private Text bestScore;
    [SerializeField]
    private GameObject panel;

    void Start()
    {
       
        

    }

    // Update is called once per frame
    void Update()
    {
      
    }

    public bool stopTrigger = true; // initially true so we game starts

    public void GameOver()
    {
        stopTrigger = false;

        StopCoroutine(CreatepoopRoutine());

        if (score >= PlayerPrefs.GetInt ("BestScore", 0))

            PlayerPrefs.SetInt("BestScore" ,score); // Save the value of score to the Bestscore variable

        bestScore.text = PlayerPrefs.GetInt("BestScore" ,0).ToString(); // Get the value stored in Bestscore variable

        panel.SetActive(true); // active = Gameover
    }

    public void GameStart()
    {
        score = 0;
        scoreTxt.text = "Score : " + score;
        stopTrigger = true;
        StartCoroutine(CreatepoopRoutine());
        panel.SetActive(false); // inactive = GameStart
    }



    public void Score()
    {
        if(stopTrigger)
        score++; // Increase the value of score by 1 whenver all the Score function
        //Debug.Log("score :" + score);
        scoreTxt.text = "score : " + score;  // show the value of score on the screen ( the text named score )

    }

    IEnumerator CreatepoopRoutine()
    {
        while (stopTrigger) // loop for poop creation
        {
            CreatePoop();
            yield return new WaitForSeconds(1); //Execute after waiting 1 second
        }    
        
    }

    private void CreatePoop()
    {
        Vector3 pos = Camera.main.ViewportToWorldPoint(new Vector3 (UnityEngine.Random.Range(0.01f, 1.0f), 1.1f, 0)); // Convert the place of the main camera to the place of World so that the poop only spawned in the main camera area
        // randomly return the value between 0.01 and 1.0 = x value, y value 1.1f , z value = 0
        pos.z = 0.0f;
        Instantiate(poop, pos, Quaternion.identity); // Quaternion.identity : the object never rotates

    }
}
